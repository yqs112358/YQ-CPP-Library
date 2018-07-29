#ifndef YQ_AUTOHANDLE
#define YQ_AUTOHANDLE

#include <windows.h>

class AutoHandle
{
	private:
		
		HANDLE hHandle;
		
		HANDLE hCopy(HANDLE hSrc)
		{
			HANDLE hBack;
			return DuplicateHandle(GetCurrentProcess(),hSrc,GetCurrentProcess(),&hBack,0,TRUE,DUPLICATE_SAME_ACCESS) ? hBack : 0;
		}
		
	public:
		
		explicit AutoHandle(HANDLE hHdl) noexcept
			 :hHandle(hHdl)
		{}
		
		AutoHandle() noexcept
			:hHandle(0)
		{}
		
		void Close() noexcept
		{
			CloseHandle(hHandle);
			hHandle=0;
		}
		
		void Set(HANDLE newh) noexcept
		{
			if(hHandle>0)
				Close();
			hHandle=newh;
			return hHandle>0;
		}
		
		explicit operator bool() const noexcept
		{
			return hHandle>0;
		}
		
		operator HANDLE() const noexcept
		{
			return hHandle;
		}
		
		
		AutoHandle(const AutoHandle &h) noexcept
			:hHandle(hCopy(h.hHandle))
		{}
		
		AutoHandle &operator=(const AutoHandle &h) noexcept
		{
			if(this != &h)
			{
				Close();
				hHandle=hCopy(h.hHandle);
			}
			return *this;
		}
		
		AutoHandle(AutoHandle &&h) noexcept
			:hHandle(h.hHandle)
		{
			h.hHandle=0;
		}
		
		AutoHandle &operator=(AutoHandle &&h) noexcept
		{
			if(this != &h)
			{
				hHandle=h.hHandle;
				h.hHandle=0;
			}
			return *this;
		}
};
		
#endif
