#include "trit.h"
#include "tritset.h" 
#include <gtest/gtest.h>
 
TEST(TritTest, BehaviorTest) 
    { 

        TritSet set(1000);

        size_t allocLength = set.capacity();

        ASSERT_TRUE(allocLength >= 1000*2 / 8 / sizeof(uint) );

        set.shrink_to_fit();

        ASSERT_TRUE(allocLength > set.capacity());


        
        Trit a = Types::False;
        Trit b = Types::True;

        std::cout << a ;

    }
 


int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}