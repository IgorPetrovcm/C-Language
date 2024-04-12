# ifndef STUDENT_FIELDS_H
# define STUDENT_FIELDS_H

# define GET_STUDENT_FIELD(x) #x

/*
  <summary>
    Для этой программы пригодиться задать макросы имен полей структур проекта.
    В будущем это поможет получать нужные значения из дерева, которые будут передаваться в метод поиска значений
    что сделает выборку значений более универсальной
   <summary>
*/

# define STUDENT_LAST_NAME last_name
# define STUDENT_LAST_NAME_STR "last_name"
# define STUDENT_FIRST_NAME first_name
# define STUDENT_FIRST_NAME_STR "first_name"
# define STUDENT_GENDER gender
# define STUDENT_GENDER_STR "gender"
# define STUDENT_AGE age
# define STUDENT_AGE_STR "age"
# define STUDENT_GROUP group
# define STUDENT_GROUP_STR "group"
# define STUDENT_ASSESSMENT_MATH assessment_by_math
# define STUDENT_ASSESSMENT_MATH_STR "assessment_by_math"
# define STUDENT_ASSESSMENT_PHYSICS assessment_by_physics
# define STUDENT_ASSESSMENT_PHYSICS_STR "assessment_by_physics"
# define STUDENT_ASSESSMENT_CHEMISTRY assessment_by_chemistry
# define STUDENT_ASSESSMENT_CHEMISTRY_STR "assessment_by_chemistry"

# endif