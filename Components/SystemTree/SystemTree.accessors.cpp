#include "SystemTree.hpp"
#include <cstddef>

const std::vector<SystemTree>	&SystemTree::getNodes(void) const
{
	return (this->_nodes);
}

//const Vector::string	&SystemTree::getPaths(void) const
//{
//	return (this->_paths);
//}

//const Vector::string	&SystemTree::getNames(void) const
//{
//	return (this->_names);
//}

const std::size_t	&SystemTree::getDeep(void) const
{
	return (this->_deep);
}

const SystemTree::status	&SystemTree::getStatus(void) const
{
	return (this->_status);
}

const SystemTree	&SystemTree::getNode(const std::string &path) const
{
	(void)path;
	return (this->_nodes[0]);
}
