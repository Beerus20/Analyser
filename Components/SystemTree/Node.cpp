#include "Node.hpp"
#include <utility>

Node::Node(void) : _filter(NodeFilterType::WITHOUT_HIDDEN) {}
Node::Node(NodeFilterType filter) : _filter(filter) {}
Node::Node(const std::string &path, NodeFilterType filter) : _filter(filter)
{
	this->_is_inited = init(path);
}

Node::Node(const Node &other)
{
	*this = other;
}

Node::Node(Node &&other)
{
	*this = std::move(other);
}

Node::~Node(void) {}

Node &Node::operator=(const Node &other)
{
	if (this != &other)
	{
		this->_stat = other._stat;
		this->_name = other._name;
		this->_path = other._path;
		this->_size = other._size;
		this->_type = other._type;
		this->_permissions = other._permissions;
		this->_filter = other._filter;
	}
	return (*this);
}

Node	&Node::operator=(Node &&other)
{
	if (this != &other)
	{
		this->_stat = std::move(other._stat);
		this->_name = std::move(other._name);
		this->_path = std::move(other._path);
		this->_size = std::move(other._size);
		this->_type = std::move(other._type);
		this->_permissions = std::move(other._permissions);
		this->_is_inited = other._is_inited;
		this->_filter = std::move(other._filter);
		other = Node();
	}
	return (*this);
}

bool	Node::init(const std::string &path)
{
	if (Node::checkFilter(path, this->_filter))
		return (false);
	if (stat(path.c_str(), &this->_stat) == -1)
	{
		perror(std::string("OPEN ( " + path+ " )").c_str());
		return (false);
	}
	this->_path = path;
	this->_type = checkType(this->_stat);
	this->_permissions = checkPermissions(this->_stat);
	this->_name = (this->_type != NodeType::DIRECTORY ? Utils::getFileName(path) : path);
	this->_size = Utils::convert<std::size_t>(this->_stat.st_size);
	return (true);
}

NodeType	Node::checkType(Stat stat)
{
	NodeType	type;

	if (S_ISREG(stat.st_mode))
		type = NodeType::FILE;
	else if (S_ISDIR(stat.st_mode))
		type = NodeType::DIRECTORY;
	else if (S_ISLNK(stat.st_mode))
		type = NodeType::LINK;
	else if (S_ISCHR(stat.st_mode))
		type = NodeType::SCHAR;
	else if (S_ISBLK(stat.st_mode))
		type = NodeType::BLOC;
	else if (S_ISFIFO(stat.st_mode))
		type = NodeType::FIFO;
	else if (S_ISSOCK(stat.st_mode))
		type = NodeType::SOCKET;
	else
		type = NodeType::UNKNOW;
	return (type);
}

Node::permissions	Node::checkPermissions(Stat stat)
{
	Node::permissions	permissions;

	permissions.user.read = (stat.st_mode & S_IRUSR);
	permissions.user.write = (stat.st_mode & S_IWUSR);
	permissions.user.execute = (stat.st_mode & S_IXUSR);
	permissions.group.read = (stat.st_mode & S_IRGRP);
	permissions.group.write = (stat.st_mode & S_IWGRP);
	permissions.group.execute = (stat.st_mode & S_IXGRP);
	permissions.other.read = (stat.st_mode & S_IROTH);
	permissions.other.write = (stat.st_mode & S_IWOTH);
	permissions.other.execute = (stat.st_mode & S_IXOTH);
	return (permissions);
}

bool	Node::checkFilter(const std::string &path, const NodeFilterType &filter)
{
	if (filter == NodeFilterType::WITHOUT_HIDDEN)
		return (path.size() > 1 && path[0] != '.' && path[1] != '/');
	if (filter == NodeFilterType::ONLY_HIDDEN)
		return (path.size() > 1 && path[0] == '.' && path[1] != '/');
	return (true);
}
