#include <iostream>
#include "Stack_imp.h"

int main(){
    Stack <int> st(20);
    st.Push(77);
    st.Push(37);
    st.Push(18);

    if(!st.isEmpty()){
        st.Pop();
    }

    if(!st.isEmpty()){
        std::cout << "Top of the stack is: " << st.Top() << std::endl;
    }

    return 0;
}
