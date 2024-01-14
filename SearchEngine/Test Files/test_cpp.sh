#Compile the code
# if the file HW1 exits then remove it
if [ -f PROJ1 ]; then
    rm PROJ1
fi
g++ PROJ1.cpp -o PROJ1
# if the file HW1 does not exit then exit the test
if [ ! -f PROJ1 ]; then
    echo   "\033[1;91mCompile FAILED.\033[0m"
    exit
fi
# clean
rm *.out *.stderr *.stdcout
./PROJ1 doc1.txt ins1.txt doc1_mat.txt ins1_out.txt 1>doc1.stdcout 2>doc1.stderr
bash -c 'diff -iEBwu doc1_mat.txt doc1_mat_GT.txt >doc1_mat_1.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case doc1 matrix build up    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case doc1 matrix build up    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff

fi
bash -c 'diff -iEBwu ins1_out.txt ins1_out_GT.txt >ins1_out_1.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case ins1 follow:    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case ins1 follow:   \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
fi


./PROJ1 doc2.txt ins2.txt doc2_mat.txt ins2_out.txt 1>doc2.stdcout 2>doc2.stderr
bash -c 'diff -iEBwu doc2_mat.txt doc2_mat_GT.txt >doc2_mat_1.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case doc2 matrix build up    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case doc2 matrix build up    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff

fi
bash -c 'diff -iEBwu ins2_out.txt ins2_out_GT.txt >ins2_out_2.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case ins2 follow:    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case ins2 follow:   \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
fi

./PROJ1 doc3.txt ins3.txt doc3_mat.txt ins3_out.txt 1>doc3.stdcout 2>doc3.stderr
bash -c 'diff -iEBwu doc3_mat.txt doc3_mat_GT.txt >doc3_mat_1.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case doc3 matrix build up    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case doc3 matrix build up    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff

fi
bash -c 'diff -iEBwu ins3_out.txt ins3_out_GT.txt >ins3_out_3.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case ins3 follow:    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case ins3 follow:   \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
fi