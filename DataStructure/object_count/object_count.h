
#ifndef _OBJECT_COUNT_H_INCLUDED
#define _OBJECT_COUNT_H_INCLUDED

//base class for private inheritance
template<class T>
class Object_count {
public:
	class Error_too_many_objects {};

	static int number();

protected:
	Object_count();
	Object_count(const Object_count& rhs);
	~Object_count();

private:
	static int object_num;
	static const int max_num;

	void init();
};

template<class T>
Object_count<T>::Object_count()
{
	init();
}

template<class T>
Object_count<T>::Object_count(const Object_count<T>& rhs)
{
	init();
}

template<class T>
Object_count<T>::~Object_count()
{
	--object_num;
}

template<class T>
int Object_count<T>::number()
{
	return object_num;
}

template<class T>
void Object_count<T>::init()
{
	if (object_num >= max_num)
		throw Error_too_many_objects();
	++object_num;
}

template<class T>
int Object_count<T>::object_num;  //define and initializes static member to 0

#endif