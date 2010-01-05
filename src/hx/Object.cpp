#include <hxcpp.h>

#include <stdio.h>
#include <hxMath.h>
//#include <hxMacros.h>
#include <cpp/CppInt32__.h>
#include <map>


#ifdef _WIN32
#include <windows.h>
#include <time.h>
#else
#include <sys/time.h>
#include <wchar.h>
typedef  uint64_t  __int64;
#endif

// Stoopid windows ...
#ifdef RegisterClass
#undef RegisterClass
#endif
#ifdef abs
#undef abs
#endif



// --- hxObject -----------------------------------------

namespace hx
{

String sNone[] = { String(null()) };

Dynamic Object::__IField(int inFieldID)
{
   return __Field( __hxcpp_field_from_id(inFieldID) );
}

double Object::__INumField(int inFieldID)
{
	return __IField(inFieldID);
}


int Object::__Compare(const Object *inRHS) const
{
   return (int)(inRHS-this);
}


Dynamic Object::__Field(const String &inString) { return null(); }
// TODO: this is not quite correct...
bool Object::__HasField(const String &inString) { return __Field(inString)!=null(); }
Dynamic Object::__Run(const Array<Dynamic> &inArgs) { return 0; }
Dynamic Object::__GetItem(int inIndex) const { return Dynamic(); }
void Object::__SetItem(int inIndex,Dynamic) {  }
DynamicArray Object::__EnumParams() { return DynamicArray(); }
String Object::__Tag() const { return L"<not enum>"; }
int Object::__Index() const { return -1; }

void Object::__SetThis(Dynamic inThis) { }

bool Object::__Is(Dynamic inClass ) const { return __Is(inClass.GetPtr()); }

static Class Object__mClass;

bool AlwaysCast(Object *inPtr) { return inPtr!=0; }

void Object::__boot()
{
   Static(Object__mClass) = RegisterClass(HX_STRING(L"Dynamic",7),AlwaysCast,sNone,sNone,0,0, 0 );
}

Class &Object::__SGetClass() { return Object__mClass; }

Class Object::__GetClass() const { return Object__mClass; }

hx::FieldRef Object::__FieldRef(const String &inString) { return hx::FieldRef(this,inString); }

String Object::__ToString() const { return L"Object"; }

char * Object::__CStr() const { return __ToString().__CStr(); }


Dynamic Object::__SetField(const String &inField,const Dynamic &inValue)
{
	throw Dynamic( String(L"Invalid field:") + inField );
	return null();
}

Dynamic Object::__run()
{
   return __Run(Array_obj<Dynamic>::__new());
}

Dynamic Object::__run(D a)
{
   return __Run( Array_obj<Dynamic>::__new(0,1) << a );
}

Dynamic Object::__run(D a,D b)
{
   return __Run( Array_obj<Dynamic>::__new(0,2) << a << b );
}

Dynamic Object::__run(D a,D b,D c)
{
   return __Run( Array_obj<Dynamic>::__new(0,3) << a << b << c);
}
Dynamic Object::__run(D a,D b,D c,D d)
{
   return __Run( Array_obj<Dynamic>::__new(0,4) << a << b << c << d);
}
Dynamic Object::__run(D a,D b,D c,D d,D e)
{
   return __Run( Array_obj<Dynamic>::__new(0,4) << a << b << c << d << e);
}
Dynamic Object::__run(D a,D b,D c,D d,D e,D f)
{
   return __Run( Array_obj<Dynamic>::__new(0,5) << a << b << c << d << e << f);
}
Dynamic Object::__run(D a,D b,D c,D d,D e,D f,D g)
{
   return __Run( Array_obj<Dynamic>::__new(0,6) << a << b << c << d << e << f << g);
}
Dynamic Object::__run(D a,D b,D c,D d,D e,D f,D g,D h)
{
   return __Run( Array_obj<Dynamic>::__new(0,7) << a << b << c << d << e << f << g << h);
}
Dynamic Object::__run(D a,D b,D c,D d,D e,D f,D g,D h,D i)
{
   return __Run( Array_obj<Dynamic>::__new(0,8) << a << b << c << d << e << f << g << h << i);
}
Dynamic Object::__run(D a,D b,D c,D d,D e,D f,D g,D h,D i,D j)
{
   return __Run( Array_obj<Dynamic>::__new(0,8) << a << b << c << d << e << f << g << h << i << j);
}
Dynamic Object::__run(D a,D b,D c,D d,D e,D f,D g,D h,D i,D j,D k)
{
   return __Run( Array_obj<Dynamic>::__new(0,9) << a << b << c << d << e << f << g << h << i << j<< k );
}

void Object::__GetFields(Array<String> &outFields)
{
}


String Object::toString() { return __ToString(); }


} // end namespace hx



