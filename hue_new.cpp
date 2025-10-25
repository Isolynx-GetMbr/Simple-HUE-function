#include <Windows.h>
#include <memory> // used for constructors (make_unique<T>();)

// lambdas makes it shorter
// only supports at C++11 and higher.
#define do_min( a, b, fa, fb ) ( [ & ]( ) { return ( a ) < ( b ) ? ( fa ) : ( fb ); } ( ) )
#define do_max( a, b, fa, fb ) ( [ & ]( ) { return ( a ) > ( b ) ? ( fa ) : ( fb ); } ( ) )

class hue
{
private:
   // array order: r (0), g (1), b (2)
   int rgb[ 3 ];
   int ph;

public:
    hue( ) // initialize
    {
        rgb[ 0 ] = 255; // r 
        rgb[ 1 ] = 0;   // g
        rgb[ 2 ] = 0;   // b

        ph = 0;         // phase of each hue values
    }

    COLORREF shift( int s )
    {
        switch ( ph )
        {
            // phases somewhat improves the transition between hue values.
            case 0: do_min( rgb[ 1 ], 255, rgb[ 1 ] += s, { rgb[ 1 ] = 255; ph = 1; } ); break;
            case 1: do_max( rgb[ 0 ], 0,   rgb[ 0 ] -= s, { rgb[ 0 ] = 0;   ph = 2; } ); break;
            case 2: do_min( rgb[ 2 ], 255, rgb[ 2 ] += s, { rgb[ 2 ] = 255; ph = 3; } ); break;
            case 3: do_max( rgb[ 1 ], 0,   rgb[ 1 ] -= s, { rgb[ 1 ] = 0;   ph = 4; } ); break;
            case 4: do_min( rgb[ 0 ], 255, rgb[ 0 ] += s, { rgb[ 0 ] = 255; ph = 5; } ); break;
            case 5: do_max( rgb[ 2 ], 0,   rgb[ 2 ] -= s, { rgb[ 2 ] = 0;   ph = 0; } ); break;
        }

        return RGB( rgb[ 0 ], rgb[ 1 ], rgb[ 2 ] );
     }
};

// usage/examples:
int main( )
{
    HDC hdc = GetDC( 0 ); // declares a handle for the device context, which is the main screen itself.
    // declares a smart pointer that owns the dynamically allocated object of the class hue. similar to
    //   hue h = new hue( );
    // in C#. But was only supported in C++14 and higher. 
    // If you want a compatible one for C++11, use 
    //   unique_ptr<hue> p( new hue( ) );
    auto a = make_unique< hue >( );
    // use it inside the csb function.
    // shift each rgb values by 2
    HBRUSH hb = CreateSolidBrush( a->shift( 2 ) );
    // then apply it with SelectObject to main DC
    SelectObject( hdc, hb );

    // any code that uses that brush ...

    // and dont forget to clear anything!
    // use DeleteObject for brushes and other GDI objects and ReleaseDC for the main dc while DeleteDC for the memory dc.
    return 0; // exits the main application.
}
