/**
* My tool box for common operation
*/

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
}