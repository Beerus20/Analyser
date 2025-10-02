#include "SystemTree.hpp"
#include <dirent.h>
#include <cstddef>
#include <cstdio>
#include <string>
#include "Node.hpp"

json	SystemTree::tree;

SystemTree::SystemTree(void) {}
SystemTree::SystemTree(const SystemTree &other) : Node(other) { *this = other; }
SystemTree::SystemTree(SystemTree &&other) noexcept : Node(std::move(other)) { *this = std::move(other); }
SystemTree::~SystemTree(void) {}
SystemTree &SystemTree::operator=(const SystemTree &other)
{
	if (this != &other)
		this->_infos = other._infos;
	return (*this);
}

SystemTree &SystemTree::operator=(SystemTree &&other) noexcept
{
	if (this != &other)
	{
		this->_infos = std::move(other._infos);
		other._infos = NULL;
	}
	return (*this);
}

std::ostream& SystemTree::print(std::ostream& os) const
{
	std::cout << this->_infos.dump(4) << std::endl;
	return os;
}

std::ostream& operator << ( std::ostream& os, const SystemTree &systemtree)
{
	return systemtree.print(os);
}

bool	SystemTree::load(const std::string &path, std::size_t deep)
{
	return (SystemTree::load(path, this->_infos, deep));
}


bool	SystemTree::load(const std::string &path, json &data, std::size_t deep)
{
	const std::string	tmp_path(this->checkPath(path));

	if (!this->init(tmp_path))
		return (false);
	this->initJsonInfo(data);
	if (deep == 0)
		return (true);
	if (this->getType() == NodeType::DIRECTORY)
	{
		if (!this->loadDirectory(tmp_path, data, --deep))
			return (false);
	}
	if (this->getType() == NodeType::UNKNOW)
		return (false);
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
	while (content != NULL)
	{
		name = content->d_name;
		if (name != "." && name != ".." && name != "./" && name != "../")
		{
			if (!this->load(path + (path == "./" || path == "/" ? "" : "/") + name, data["contents"][name], deep))
				return (false);
		}
		content = readdir(dir);
	}
	closedir(dir);
	return (true);
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
		tmp = "./" + (tmp == "." ? "" : tmp);
	return (tmp);
}

void	SystemTree::initJsonInfo(json &data)
{
	const Node::permissions	&permissions(this->getPersmissions());

	data = json();
	data["path"] = this->getPath();
	data["size"] = this->getSize();
	data["permissions"] = {
		{"user", {permissions.user.read, permissions.user.write, permissions.user.execute}},
		{"group", {permissions.group.read, permissions.group.write, permissions.group.execute}},
		{"other", {permissions.other.read, permissions.other.write, permissions.other.execute}}
	};
	data["type"] = this->getType();
}