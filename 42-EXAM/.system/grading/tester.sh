FILE='filter.c'
ASSIGN='filter'

bash .system/auto_correc_program.sh $FILE $ASSIGN "abc"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "test"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "hello"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
