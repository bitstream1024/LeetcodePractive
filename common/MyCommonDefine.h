/**
* My tool box for common operation
*/
#include "stdio.h"
#include <iostream>
#include <vector>
#include <string>

#pragma once

namespace cg_tool
{
	template <typename T> static void Exchange(T &var1, T &var2)
	{
		T temp = var1;
		var1 = var2;
		var2 = temp;
		return;
	}

	template <typename T> static T Min(const T &var1, const T &var2)
	{
		return var1 <= var2 ? var1 : var2;
	}

	template <typename T> static T Max(const T &var1, const T &var2)
	{
		return var1 <= var2 ? var2 : var1;
	}

	//template <typename T> static void PrintList(const std::vector<T> &list, std::string strInfo)
	//{
	//	std::count << strInfo.c_str() << "PrintList: " << std::endl;
	//	for (size_t i = 0; i < list.size(); ++i)
	//	{
	//		//std::count << "list[" << i << "]" << list[i] << std::endl;			
	//	}
	//}
}