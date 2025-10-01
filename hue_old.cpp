// [2025年9月30日, GetMbr/Isolynx] commenting on my old code
/* hsl.cpp by GetMbr, please do not skid! */
#include <Windows.h>

// no need for this.
#define Integer int

// int r, g, b;
// and don't forget to initialize it first!
Integer red, green, blue;
bool ifcolorblue = false, ifblue = false;
COLORREF Hue(Integer length) {
	// large blocks of code, I will shorten it if possible.
	if (red != length) {
		// forgot to use the if statement back then lmao.
		// I was too braindead as always.
		red < length; red++;
		// use tenary operators instead.
		if (ifblue == true) {
			return RGB(red, 0, length);
		}
		else {
			return RGB(red, 0, 0);
		}
	}
	else {
		if (green != length) {
			green < length; green++;
			return RGB(length, green, 0);
		}
		else {
			if (blue != length) {
				blue < length; blue++;
				return RGB(0, length, blue);
			}
			else {
				// should be commas instead of semicolons.
				red = 0; green = 0; blue = 0;
				ifblue = true;
			}
		}
	}
}

int main() { 
   // Use this code inside CreateSolidBrush Function. 
   // e.g. SelectObject(dc, <- main DC (device context)
   // 			CreateSolidBrush(Hue(255)) <- like this.
   //	   ); <- then apply it to the main DC.
}

