#include <iostream>

using namespace std;

class Counter{
    static int count;

    public:
        Counter() {count++;}

       int getCount(){
            return count;
        }
};

int Counter::count=0;

class Toy {
    public:
         Toy(string name) {}
    };
    
    // Error due to explicit constructor

    #include <iostream>
#include <string>
using namespace std;

class Toy {
public:
    Toy(string name) { // Constructor without `explicit`
        cout << "Toy created: " << name << endl;
    }
};

int main() {
    Toy t = "Car"; // Implicit conversion from string to Toy
    return 0;
}

// int main(){
//     Counter c1,c2,c3;
//     Toy t = "Car"; 
//     // cout<<c1.getCount()<<c2.getCount()<<c3.getCount()<<endl;
// }