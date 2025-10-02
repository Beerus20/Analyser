#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>
# include <dirent.h>
# include <sys/stat.h>
# include "../Utils/Utils.hpp"

typedef struct stat	Stat;

enum NodeType
{
	NODE_DIRECTORY,
	NODE_FILE,
	NODE_LINK,
	NODE_SCHAR,
	NODE_BLOC,
	NODE_FIFO,
	NODE_SOCKET,
	NODE_UNKNOW
};

class Node
{
	public:
		struct permission
		{
			bool	read;
			bool	write;
			bool	execute;
		};
		struct permissions
		{
			permission	user;
			permission	group;
			permission	other;
		};

		Node(void);
		Node(const std::string &path);
		Node(const Node&);
		virtual ~Node(void);
		Node				&operator=(const Node&);
		std::ostream		&print(std::ostream& os) const;

		const std::string	&getName(void) const;
		const std::string	&getPath(void) const;
		const NodeType		&getType(void) const;
		const permissions	&getPersmissions(void) const;
		const std::string	getStringSize(void) const;
		std::size_t			getSize(void) const;

		std::size_t			getPathSize(void) const;
		std::size_t			getNameSize(void) const;

		const bool			&isInited(void) const;

		bool				init(const std::string &path);

		static NodeType		checkType(Stat stat);
		static permissions	checkPermissions(Stat stat);


	private:
		Stat				_stat;
		std::string			_name;
		std::string			_path;
		std::size_t			_size;
		NodeType			_type;
		permissions			_permissions;
		bool				_is_inited;

};

std::ostream& operator << ( std::ostream& os, const Node &node);

#endif