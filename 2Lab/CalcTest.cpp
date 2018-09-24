#include"StackCalc.h"
#include <gtest/gtest.h>


TEST(CalcTest , BehaviorTest){
    StackCalc st("file.txt");
    st.start();
}

int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}