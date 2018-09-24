#include "trit.h"
#include "tritset.h" 
#include <gtest/gtest.h>

Trit operator&(Trit const & self, Trit const & obj);

 
TEST(TritTest, BehaviorTest) 
    { 

        TritSet set(1000);
        size_t allocLength = set.capacity();
        EXPECT_TRUE(allocLength >= 1000*2 / 8 / sizeof(uint) );

        set.shrink_to_fit();
        EXPECT_TRUE(allocLength > set.capacity());
        EXPECT_EQ(set.capacity() , 0);


        set.resize(2);
        EXPECT_EQ(set.capacity() , 2);



        set[0] = Types::True;
        set[1] = Types::False;
        Trit a = (set[0] & set[1]);
        EXPECT_EQ(a , Types::False);

        TritSet set1(10);
        TritSet set2(10);
        for(int i = 0; i < set1.capacity(); ++i){
            set1[i] = Types::True;
            set2[i] = Types::False;
        }
        TritSet set3 = (set1 & set2);
        EXPECT_EQ(set3.cardinality(Types::False) , 10);
        EXPECT_EQ(set3.cardinality(Types::True) , 0);


        Trit t = Types::False;
        EXPECT_EQ(!t , Types::True);

        TritSet huge(1000000);
    }



int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}