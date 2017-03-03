Student * createStudent(const char *firstName, const char *lastName, int id, double gpa) {
  Student *s;

  s = (Student *) malloc(sizeof(Student) * 1); 

  s->id = id;
  s->gpa = gpa;

  s->firstName = (char *) malloc(sizeof(char) * (strlen(firstName) + 1));
  strcpy(s->firstName, firstName);

  s->lastName =       (char *) malloc(sizeof(char) * (strlen(lastName) + 1));
  strcpy(s->lastName, lastName);

  //TODO: support dateOfBirth at some point
  //note: 
  //s->dateOfBirth.year = 1978

  return s;
}

//deep copy
void copy_Student(Student *s1, Student *s2)
{
    s2 -> grade = s1 -> grade;
    s2 -> id = s2 -> id;
    s2 -> first_name = strdup(s1 -> first_name);
    s2 -> last_name = strdup(s1 -> last_name);
}