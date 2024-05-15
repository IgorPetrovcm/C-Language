# ifndef STRUCT_STUDENT
# define STRUCT_STUDENT

# include "student_fields_macroses.h"

struct student{
    char* STUDENT_LAST_NAME;
    char* STUDENT_FIRST_NAME;
    char STUDENT_GENDER;
    char STUDENT_AGE;
    char* STUDENT_GROUP;
    char STUDENT_ASSESSMENT_MATH;
    char STUDENT_ASSESSMENT_PHYSICS;
    char STUDENT_ASSESSMENT_CHEMISTRY;
};

# endif