#include <Windows.h>
#include <memory> // used for constructors (make_unique<T>();)

// lambdas makes it shorter
// only supports at C++11 and higher.
#define do_min( a, b, fa, fb ) ( ( a ) < ( b ) ? ( [ & ]( ) { fa; }( ) ) : ( [ & ]( ) { fb; }( ) ) )
#define do_max( a, b, fa, fb ) ( ( a ) > ( b ) ? ( [ & ]( ) { fa; }( ) ) : ( [ & ]( ) { fb; }( ) ) )

class hue
{
private:
   // array order: r, g, b
   int rgb[ 3 ];
   int ph;

public:
    hue( ) // initialize
    {
        rgb[ 0 ] = 255; // r 
        rgb[ 1 ] = 0;   // g
        rgb[ 2 ] = 0;   // b

        ph = 0;         // phase of each rgb values
    }

    COLORREF shift( int s )
    {
        switch ( ph )
        {
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
    // declares a smart pointer that owns the dynamically allocated object of the class hue. similar to
    //   hue h = new hue( );
    // in C#. But was only supported in C++14 and higher. 
    // If you want a compatible one for C++11, use 
    //   unique_ptr<hue> p( new hue( ) );
    auto a = make_unique< hue >( );
    // use it inside the csb function.
    // shift each rgb values by 2
    CreateSolidBrush( a->shift( 2 ) );
    // then apply it with SelectObject to main DC.

    return 0;
}
