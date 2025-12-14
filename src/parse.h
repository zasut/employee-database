#ifndef PARSE_H
#define PARSE_H

#define HEADER_MAGIC 0x4c4c4144

struct dbheader_t {
    unsigned int magic;
    unsigned short version;
    unsigned short count;
    unsigned int filesize;
};

struct employee_t {
    char name[256];
    char address[256];
    unsigned int salary;
};

int create_db_header(int fd, struct dbheader_t **headerOut);
int validate_db_header(int fd, struct dbheader_t **headerOUt);
int read_employees(int fd, struct dbheader_t *, struct employee_t **employeesOut);
void output_file(int fd, struct dbheader_t *, struct employee_t *employees); 
int add_employee(struct dbheader_t *, struct employee_t **employees, char *);
void list_employees(struct dbheader_t *, struct employee_t *employees);
int delete_employee(struct dbheader_t *, struct employee_t *employees, char *);
int update_employee(struct dbheader_t *, struct employee_t *employees, char *, char *);


#endif