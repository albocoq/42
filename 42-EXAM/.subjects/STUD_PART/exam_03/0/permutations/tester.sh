FILE='permutations.c'
ASSIGN='permutations'

bash .system/auto_correc_program.sh $FILE $ASSIGN "abc"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "abcd"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "xyz"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
