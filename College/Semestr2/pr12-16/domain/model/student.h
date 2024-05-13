# ifndef STUDENT_STRUCT
# define STUDENT_STRUCT

typedef struct student {
    char last_name[35];
    char first_name[35];
    char gender;
    char age;
    char group[4];
    char math_score;
    char physics_score;
    char chemistry_score;

} student;

# endif