#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template <class T> class Singleton
{
private:
	static T*     s_instance;

public:
	virtual ~Singleton(){ }

	static T*     GetInstance()
	{
		{
			if (!s_instance)
			s_instance = new T();
			return s_instance;
		}
	}
};

template <class T>
T* Singleton<T>::s_instance = NULL;

#endif