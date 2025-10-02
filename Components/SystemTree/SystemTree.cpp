#include "SystemTree.hpp"
#include <dirent.h>
#include <cstddef>
#include <cstdio>
#include <string>
#include "Node.hpp"

json	SystemTree::tree;

SystemTree::SystemTree(void) {}
SystemTree::SystemTree(const SystemTree &other) : Node(other) { *this = other; }
SystemTree::SystemTree(const SystemTree &&other) : Node(std::move(other)) { *this = std::move(other); }
SystemTree::~SystemTree(void) {}
SystemTree &SystemTree::operator=(const SystemTree &other)
{
	if (this != &other)
		this->_infos = other._infos;
	return (*this);
}

SystemTree &SystemTree::operator=(const SystemTree &&other)
{
	if (this != &other)
		this->_infos = std::move(other._infos);
	return (*this);
}

std::ostream& SystemTree::print(std::ostream& os) const
{
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
	return (true);
}

bool	SystemTree::loadDirectory(const std::string &path, json &data, std::size_t deep)
{
	DIR				*dir;
	Dirent			content;
	std::string		name;

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
