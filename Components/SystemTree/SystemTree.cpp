#include "SystemTree.hpp"
#include <dirent.h>
#include <cstddef>
#include <cstdio>
#include <string>
#include <vector>
#include "Node.hpp"

json	SystemTree::tree;

SystemTree::SystemTree(void) : _status(FAILED)
{
	this->_infos[PATHS] = std::vector<std::string>();
	this->_infos[NAMES] = std::vector<std::string>();
}

SystemTree::SystemTree(const SystemTree &other) : Node(other) { *this = other; }
SystemTree::~SystemTree(void) {}
SystemTree &SystemTree::operator=(const SystemTree &other)
{
	if (this != &other)
	{
		this->_infos[PATHS] = other._infos[PATHS];
		this->_infos[NAMES] = other._infos[NAMES];
		this->_deep = other._deep;
		this->_nodes = other._nodes;
		this->_status = other._status;
	}
	return (*this);
}

std::ostream& SystemTree::print(std::ostream& os) const
{
	os << this->getPath() << std::endl;
	for (std::vector<SystemTree>::const_iterator node(this->_nodes.begin()); node != this->_nodes.end(); node++)
		os << *node;
	return os;
}

std::ostream& operator << ( std::ostream& os, const SystemTree &systemtree)
{
	return systemtree.print(os);
}

bool	SystemTree::load(const std::string &path, json &data, std::size_t deep)
{
	const std::string	tmp_path(this->checkPath(path));

	if (!this->init(tmp_path))
		return (false);
	if (deep == 0)
		return (true);
	if (this->getType() == NODE_DIRECTORY)
	{
		if (!this->loadDirectory(tmp_path, data, --deep))
			return (this->clear(), false);
	}
	if (this->getType() == NODE_UNKNOW)
		return (this->clear(), false);
	this->_status = SUCCESS;
	return (true);
}

bool	SystemTree::loadDirectory(const std::string &path, json &data, std::size_t deep)
{
	DIR				*dir;
	Dirent			content;
	std::string		name;

	(void)deep;
	dir = opendir(path.c_str());
	if (dir == NULL)
		return (false);
	content = readdir(dir);
	data = json();
	data["path"] = path;
	while (content != NULL)
	{
		name = content->d_name;
		if ((!name.empty() && name[0] != '.') && name != ".." && name != "./" && name != "../")
		{
			data["contents"][name] = "";
			if (!this->load(path + (path == "./" || path == "/" ? "" : "/") + name, data["contents"][name], deep))
				return (false);
		}
		content = readdir(dir);
	}
	closedir(dir);
	return (true);
}

void	SystemTree::clear(void)
{
	this->_nodes.clear();
	this->_infos[NAMES].clear();
	this->_infos[PATHS].clear();
	this->_deep = 1;
	this->_status = FAILED;
}

std::string	SystemTree::checkPath(const std::string &path)
{
	std::string	tmp(path);
	std::size_t	pos(0);

	if (tmp == "/" || tmp == "./")
		return (tmp);
	Utils::removeAll(tmp, "./", 0);
	Utils::replaceAll(tmp, "//", "/");
	pos = tmp.length() - 1;
	while (pos != 0 && tmp[pos] == '/')
		pos--;
	tmp = tmp.erase(pos + 1);
	if (tmp != "/")
		tmp = "./" + tmp;
	return (tmp);
}

const SystemTree	*SystemTree::findNode(const std::string &path)
{
	std::string	tmp_path(this->checkPath(path));

	if (this->getPath() == tmp_path)
		return (this);
	for (std::size_t i(0); i < this->_nodes.size(); i++)
	{
		if (tmp_path.compare(0,this->_nodes[i].getPathSize(), this->_nodes[i].getPath()) == 0)
			return (this->_nodes[i].findNode(tmp_path));
	}
	return (NULL);
}

