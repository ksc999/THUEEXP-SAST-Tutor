#include<iostream>
namespace Tsinghua {
    namespace EE {
        namespace Sophomore {
            double GPA = 4.0;
        }
    }
}
namespace not_me = Tsinghua::EE::Sophomore;
int main() {
    std::cout << not_me::GPA << std::endl;
    return 0;
}