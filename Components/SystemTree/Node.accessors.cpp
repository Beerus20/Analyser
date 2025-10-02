#include "Node.hpp"

const std::string	&Node::getName(void) const
{
	return (this->_name);
}

const std::string	&Node::getPath(void) const
{
	return (this->_path);
}

const std::string	Node::getStringSize(void) const
{
	return (Utils::convert<std::string>(this->_size));
}

std::size_t	Node::getSize(void) const
{
	return (this->_size);
}

const NodeType	&Node::getType(void) const
{
	return (this->_type);
}

const Node::permissions	&Node::getPersmissions(void) const
{
	return (this->_permissions);
}

const bool	&Node::isInited(void) const
{
	return (this->_is_inited);
}

std::size_t	Node::getPathSize(void) const
{
	return (this->_path.size());
}

std::size_t	Node::getNameSize(void) const
{
	return (this->_name.size());
}
