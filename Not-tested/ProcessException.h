#ifndef YQ_PROCESS_EXCEPTION_H
#define YQ_PROCESS_EXCEPTION_H

#include <iostream>
#include <exception>
#include <stdexcept>
#include <system_error>

template <typename T>
void CodeException(const T &e,ostream &eout)
{
	using namespace std;
	
	auto c=e.code();
	eout << "\t-type:\t" << c.category().name() << endl;
	eout << "\t-value:\t" << c.value() << endl;
	eout << "\t-msg:\t" << c.message() << endl;
}

void ProcessException(ostream &eout,bool moreinfo=true)
{
	using namespace std;
	
	try
	{
		throw;
	}
	catch(const ios_base::failure &e)
	{
		eout << "I/O Exception:" << e.what() << endl;
		if(moreinfo)
			CodeException(e,eout);
	}
	catch(const system_error &e)
	{
		eout << "System Exception:" << e.what() << endl;
		if(moreinfo)
			CodeException(e,eout);
	}
	
	catch(const bad_alloc &e)
	{
		eout << "Bad Alloc:" << e.what() << endl;
	}
	catch(const domain_error &e)
	{
		eout << "Domain Error:" << e.what() << endl;
	}
	catch(const invalid_argument &e)
	{
		eout << "Invalid Argument:" << e.what() << endl;
	}
	catch(const length_error &e)
	{
		eout << "Length Error:" << e.what() << endl;
	}
	catch(const out_of_range &e)
	{
		eout << "Out of Range:" << e.what() << endl;
	}
	
	catch(const range_error &e)
	{
		eout << "Range Error:" << e.what() << endl;
	}
	catch(const overflow_error &e)
	{
		eout << "Overflow Error:" << e.what() << endl;
	}
	catch(const underflow_error &e)
	{
		eout << "Underflow Error:" << e.what() << endl;
	}
	catch(const bad_weak_ptr &e)
	{
		eout << "Bad Weak Ptr:" << e.what() << endl;
	}
	catch(const bad_functional_call &e)
	{
		eout << "Bad Functional Call:" << e.what() << endl;
	}
	catch(const exception &e)
	{
		eout << "Exception:" << e.what() << endl;
	}
	catch(...)
	{
		eout << "Unknown Exception!" << endl;
	}
}

#endif
