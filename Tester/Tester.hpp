#ifndef __TESTER_HPP__
# define __TESTER_HPP__

class Expect
{
	public:
		Expect(void);
		Expect(Expect const &);
		~Expect(void);
		Expect *_not;
};

#endif
