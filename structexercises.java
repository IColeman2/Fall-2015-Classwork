public Course(String title, String number) {
	super();
	this.title = title;
	this.number = number;
	this.roster = new ArrayList<Student>();
}

//copy constructor
public Course(Course c) {
	this(c.title, c.number, c.roster);
}