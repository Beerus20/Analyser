#include "SystemTree.hpp"
#include <cstddef>

const json	&SystemTree::getPaths(void) const
{
	return (this->_infos[PATHS]);
}

const json	&SystemTree::getNames(void) const
{
	return (this->_infos[NAMES]);
}
