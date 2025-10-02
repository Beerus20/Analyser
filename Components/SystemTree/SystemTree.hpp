#ifndef __HTTPSYSTEMTREE_HPP__
# define __HTTPSYSTEMTREE_HPP__

# include "../Utils/Data.hpp"
# include <cstddef>
# include <string>
# include <vector>
# include <dirent.h>
# include "Node.hpp"

# define PATHS	"paths"
# define NAMES	"names"

typedef struct dirent *		Dirent;

class SystemTree : public Node
{
	public:
		static json	tree;
		enum status
		{
			SUCCESS,
			FAILED
		};

		SystemTree (void);
		SystemTree (const SystemTree&);
		~SystemTree (void);
		SystemTree &operator = (const SystemTree&);
		std::ostream& print(std::ostream& os) const;

		bool	load(const std::string &path, json &data, std::size_t deep = 1);
		bool	loadDirectory(const std::string &path, json &data, std::size_t deep = 0);

		// accessors
		const std::vector<SystemTree>		&getNodes(void) const;
		const SystemTree					&getNode(const std::string &path) const;
		const json							&getPaths(void) const;
		const json							&getNames(void) const;
		const std::size_t					&getDeep(void) const;
		const status						&getStatus(void) const;

		void								clear(void);
		const SystemTree					*findNode(const std::string &path);

	private:
		Data								_infos;
		std::vector<SystemTree>				_nodes;
		std::size_t							_deep;
		status								_status;

		std::string							checkPath(const std::string &path);

};

std::ostream& operator << ( std::ostream& os, const SystemTree &httpsystemtree);

#endif