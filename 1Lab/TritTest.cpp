#include "trit.h"
#include "tritset.h" 
#include <gtest/gtest.h>
 
TEST(TritTest, BehaviorTest) 
    { 
    //резерв памяти для хранения 1000 тритов
    TritSet set(1000); 
    // length of internal array
    size_t allocLength = set.capacity();
    ASSERT_TRUE(allocLength >= 1000*2 / 8 / sizeof(uint) );
    // 1000*2 - min bits count
    // 1000*2 / 8 - min bytes count
    // 1000*2 / 8 / sizeof(uint) - min uint[] size

    //освобождение памяти до начального значения или 
    //до значения необходимого для хранения последнего установленного трита
    //в данном случае для трита 1000’000
    set.shrink_to_fit(); 
    ASSERT_TRUE(allocLength > set.capacity());

    //ASSERT_EQ(9, set.capacity());
    }
 


int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}