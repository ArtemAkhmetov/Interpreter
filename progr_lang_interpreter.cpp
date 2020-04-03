#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

enum type_of_lex {
  LEX_NULL, LEX_AND, LEX_BEGIN, LEX_BOOL, LEX_DO, LEX_ELSE, LEX_END, LEX_IF, LEX_FALSE, LEX_INT,
  LEX_STRING, LEX_NOT, LEX_OR, LEX_PROGRAM, LEX_READ, LEX_TRUE, LEX_WHILE, LEX_BREAK, LEX_WRITE, 
  LEX_FIN, LEX_SEMICOLON, LEX_COMMA, LEX_COLON, LEX_ASSIGN, LEX_LPAREN, LEX_RPAREN, LEX_EQ, 
  LEX_LSS, LEX_GTR, LEX_PLUS, LEX_MINUS, LEX_TIMES, LEX_SLASH, LEX_MOD, LEX_LEQ, LEX_NEQ, LEX_GEQ, 
  LEX_NUM, LEX_STRC, LEX_ID, POLIZ_LABEL, POLIZ_ADDRESS, POLIZ_GO, POLIZ_FGO, LEX_UMINUS, LEX_UPLUS
};

class Lex {
    type_of_lex t_lex;
    int v_lex;
public:
    Lex(type_of_lex t = LEX_NULL, int v = 0): t_lex(t), v_lex(v) {}
    type_of_lex get_type() const { return t_lex; }
    int get_value() const { return v_lex; }
    friend std::ostream& operator<<(std::ostream&, Lex);
};

std::ostream& operator<<(std::ostream &out, Lex l) {
    switch(l.t_lex) {
    case 0:
        out << "(LEX_NULL, " << l.v_lex << ");";
        break;
    case 1:
        out << "(LEX_AND, " << l.v_lex << ");";
        break;
    case 2:
        out << "(LEX_BEGIN, " << l.v_lex << ");";
        break;
    case 3:
        out << "(LEX_BOOL, " << l.v_lex << ");";
        break;
    case 4:
        out << "(LEX_DO, " << l.v_lex << ");";
        break;
    case 5:
        out << "(LEX_ELSE, " << l.v_lex << ");";
        break;
    case 6:
        out << "(LEX_END, " << l.v_lex << ");";
        break;
    case 7:
        out << "(LEX_IF, " << l.v_lex << ");";
        break;
    case 8:
        out << "(LEX_FALSE, " << l.v_lex << ");";
        break;
    case 9:
        out << "(LEX_INT, " << l.v_lex << ");";
        break;
    case 10:
        out << "(LEX_STRING, " << l.v_lex << ");";
        break;
    case 11:
        out << "(LEX_NOT, " << l.v_lex << ");";
        break;
    case 12:
        out << "(LEX_OR, " << l.v_lex << ");";
        break;
    case 13:
        out << "(LEX_PROGRAM, " << l.v_lex << ");";
        break;
    case 14:
        out << "(LEX_READ, " << l.v_lex << ");";
        break;
    case 15:
        out << "(LEX_TRUE, " << l.v_lex << ");";
        break;
    case 16:
        out << "(LEX_WHILE, " << l.v_lex << ");";
        break;
    case 17:
        out << "(LEX_BREAK, " << l.v_lex << ");";
        break;
    case 18:
        out << "(LEX_WRITE, " << l.v_lex << ");";
        break;
    case 19:
        out << "(LEX_FIN, " << l.v_lex << ");";
        break;
    case 20:
        out << "(LEX_SEMICOLON, " << l.v_lex << ");";
        break;
    case 21:
        out << "(LEX_COMMA, " << l.v_lex << ");";
        break;
    case 22:
        out << "(LEX_COLON, " << l.v_lex << ");";
        break;
    case 23:
        out << "(LEX_ASSIGN, " << l.v_lex << ");";
        break;
    case 24:
        out << "(LEX_LPAREN, " << l.v_lex << ");";
        break;
    case 25:
        out << "(LEX_RPAREN, " << l.v_lex << ");";
        break;
    case 26:
        out << "(LEX_EQ, " << l.v_lex << ");";
        break;
    case 27:
        out << "(LEX_LSS, " << l.v_lex << ");";
        break;
    case 28:
        out << "(LEX_GTR, " << l.v_lex << ");";
        break;
    case 29:
        out << "(LEX_PLUS, " << l.v_lex << ");";
        break;
    case 30:
        out << "(LEX_MINUS, " << l.v_lex << ");";
        break;
    case 31:
        out << "(LEX_TIMES, " << l.v_lex << ");";
        break;
    case 32:
        out << "(LEX_SLASH, " << l.v_lex << ");";
        break;
    case 33:
        out << "(LEX_MOD, " << l.v_lex << ");";
        break;
    case 34:
        out << "(LEX_LEQ, " << l.v_lex << ");";
        break;
    case 35:
        out << "(LEX_NEQ, " << l.v_lex << ");";
        break;
    case 36:
        out << "(LEX_GEQ, " << l.v_lex << ");";
        break;
    case 37:
        out << "(LEX_NUM, " << l.v_lex << ");";
        break;
    case 38:
        out << "(LEX_STRC, " << l.v_lex << ");";
        break;
    case 39:
        out << "(LEX_ID, " << l.v_lex << ");";
        break;
    case 40:
        out << "(POLIZ_LABEL, " << l.v_lex << ");";
        break;
    case 41:
        out << "(POLIZ_ADDRESS, " << l.v_lex << ");";
        break;
    case 42:
        out << "(POLIZ_GO, " << l.v_lex << ");";
        break;
    case 43:
        out << "(POLIZ_FGO, " << l.v_lex << ");";
        break;
    case 44:
        out << "(LEX_UMINUS, " << l.v_lex << ");";
        break;
    case 45:
        out << "(LEX_UPLUS, " << l.v_lex << ");";
        break;
    default:
        throw "unexpected lexeme";
    }
    return out;
}

class Ident {
    std::string name;
    bool declare;
    type_of_lex type;
    bool assign;
    int value;
public:
    Ident() { declare = false; assign = false; }
    Ident(const std::string n) { name = n; declare = false; assign = false; }
    bool operator==(const std::string &s) const { return name == s; }
    const std::string& get_name() const { return name; }
    bool get_declare() const { return declare; }
    void put_declare() { declare = true; }
    type_of_lex get_type() const { return type; }
    void put_type(type_of_lex t) { type = t; }
    bool get_assign() const { return assign; }
    void put_assign() { assign = true; }
    int get_value() const { return value; }
    void put_value(int v) { value = v; }
};

std::vector<Ident> TID;
std::vector<std::string> TS;

int put_TID(const std::string &buf) {
    std::vector<Ident>::iterator it;
    if ((it = std::find(TID.begin(), TID.end(), buf)) != TID.end())
        return it - TID.begin();
    TID.push_back(Ident(buf));
    return TID.size() - 1;
}

int put_TS(const std::string &buf) {
    std::vector<std::string>::iterator it;
    if ((it = std::find(TS.begin(), TS.end(), buf)) != TS.end())
        return it - TS.begin();
    TS.push_back(buf);
    return TS.size() - 1;
}

class Scanner {
    enum state { H, IDENT, STR, NUMB, COM, ALE, NEQ };
    static const char *TW[], *TD[];
    FILE *fp;
    char c;
    int look(const std::string &buf, const char **list) {
        int i = 0;
        while (list[i]) {
            if (buf == list[i])
                return i;
            ++i;
        }
        return 0;
    }
    void gc() { c = fgetc(fp); }
public:
    Lex get_lex();
    Scanner(const char *program) { 
        if ((fp = fopen(program, "r")) == NULL)
            throw "couldn't open the file";
    }
    ~Scanner() { if (fp) fclose(fp); }
};

const char *Scanner::TW[] = 
{
    "", "and", "{", "boolean", "do", "else", "}", "if", "false", "int", "string", 
    "not", "or", "program", "read", "true", "while", "break", "write", NULL
};

const char *Scanner::TD[] = 
{
    "", ";", ",", ":", "=", "(", ")", "==", "<", 
    ">", "+", "-", "*", "/", "%", "<=", "!=", ">=", NULL
};

Lex Scanner::get_lex() {
    int d, j;
    std::string buf;
    char a = '0';
    state CS = H;
    do {
        gc();
        switch(CS) {
        case H:
            if (a != '/' && (c == ' ' || c == '\n' || c == '\r' || c == '\t')); 
            else if (a != '/' && isalpha(c)) {
                buf.push_back(c);
                CS = IDENT;
            }
            else if (a != '/' && isdigit(c)) {
                d = c - '0';
                CS = NUMB;
            }
            else if (a != '/' && c == '\"')
                CS = STR;
            else if (a != '/' && c == '/')
                a = '/';
            else if (a == '/' && c == '*') {
                a = '0';
                CS = COM;
            }
            else if (a != '/' && (c == '=' || c == '<' || c == '>')) { 
                buf.push_back(c);
                CS = ALE;
            }
            else if (a != '/' && c == EOF)
                return Lex(LEX_FIN);
            else if (a != '/' && c == '!') {
                buf.push_back(c);
                CS = NEQ;
            }
            else {
                if (a == '/') {
                    ungetc(c, fp);
                    c = a;
                    a = '0';
                }
                buf.push_back(c);
                if ((j = look(buf, TD))) {
                    return Lex((type_of_lex)(j+(int)LEX_FIN), j);
                }
                else if (buf == "{")
                    return Lex(LEX_BEGIN, 2);
                else if (buf == "}")
                    return Lex(LEX_END, 6);
                else
                    throw c;
            }
            break;
        case IDENT: 
            if (isalpha(c) || isdigit(c))
                buf.push_back(c); 
            else {
                ungetc(c, fp);
                if ((j = look(buf, TW)))
                    return Lex((type_of_lex)j, j);
                else {
                    j = put_TID(buf);
                    return Lex(LEX_ID, j);
                }
            }
            break;
        case STR:
            if (c == EOF)
                throw c;
            else if (c != '\"') 
                buf.push_back(c);
            else {
                j = put_TS(buf);
                return Lex(LEX_STRC, j);
            }
            break;
        case NUMB: 
            if (isdigit(c))
                d = d * 10 + (c - '0'); 
            else {
                ungetc(c, fp);
                return Lex(LEX_NUM, d);
            }
            break;
        case COM:
            if (c == '*')
                a = '*';
            else if (a == '*' && c == '/') {
                a = '0';
                CS = H;
            }
            else if (c == EOF)
                throw c;
            break;
        case ALE: 
            if (c == '=') {
                buf.push_back(c);
                j = look(buf, TD);
                return Lex((type_of_lex)(j+(int)LEX_FIN), j);
            }
            else {
                ungetc(c, fp);
                j = look(buf, TD);
                return Lex((type_of_lex)(j+(int)LEX_FIN), j);
            }
            break;
        case NEQ: 
            if (c == '=') {
                buf.push_back(c);
                j = look(buf, TD);
                return Lex(LEX_NEQ, j);
            }
            else
                throw '!';
            break;
        }
    } while (true);
}

class Parser {
    Lex curr_lex;
    type_of_lex c_type;
    int c_val;
    Scanner scan;
    std::stack<int> st_int;
    std::stack<type_of_lex> st_lex;
    void P();
    void D();
    void B();
    void S();
    void S1();
    void E0();
    void E1();
    void E2();
    void E3();
    void E4();
    void T();
    void T1();
    void F();
    void dec(type_of_lex type);
    void check_id();
    void check_op();
    void check_not();
    void check_uminus();
    void check_uplus();
    void eq_type();
    void eq_bool();
    void check_id_in_read();
    void gl() {
        curr_lex = scan.get_lex();
        c_type = curr_lex.get_type();
        c_val = curr_lex.get_value();
        std::cout << curr_lex << std::endl;
    }
public:
    std::vector <Lex> poliz;
    Parser(const char *program) : scan(program) {}
    void analyze();
};

void Parser::analyze() {
    gl();
    P();
    if (c_type != LEX_FIN)
        throw curr_lex;
    std::cout << std::endl << "POLIZ:" << std::endl;
    for (Lex l : poliz)
        std::cout << l << std::endl;
    std::cout << std::endl << "Yes!" << std::endl;
}

void Parser::P() {
    if (c_type == LEX_PROGRAM)
        gl();
    else
        throw curr_lex;
    if (c_type == LEX_BEGIN)
        gl();
    else 
        throw curr_lex;
    D();
    B();
    if (c_type == LEX_END)
        gl();
    else
        throw curr_lex;
}

void Parser::D() {
    if (c_type == LEX_INT) {
        gl();
        if (c_type != LEX_ID)
            throw curr_lex;
        else {
            st_int.push(c_val);
            gl();
            if (c_type == LEX_ASSIGN) {
                gl();
                if (c_type == LEX_NUM) {
                    TID[st_int.top()].put_value(c_val);
                    TID[st_int.top()].put_assign();
                    gl();
                }
                else
                    throw curr_lex;
            }
            while (c_type == LEX_COMMA) {
                gl();
                if (c_type != LEX_ID)
                    throw curr_lex;
                else {
                    st_int.push(c_val);
                    gl();
                    if (c_type == LEX_ASSIGN) {
                        gl();
                        if (c_type == LEX_NUM) {
                            TID[st_int.top()].put_value(c_val);
                            TID[st_int.top()].put_assign();
                            gl();
                        }
                        else
                            throw curr_lex;
                    }
                }
            }
            if (c_type == LEX_SEMICOLON) {
                dec(LEX_INT);
                gl();
                D();
            }
            else
                throw curr_lex;
        }
    }
    else if (c_type == LEX_STRING) {
        gl();
        if (c_type != LEX_ID)
            throw curr_lex;
        else {
            st_int.push(c_val);
            gl();
            if (c_type == LEX_ASSIGN) {
                gl();
                if (c_type == LEX_STRC) {
                    TID[st_int.top()].put_value(c_val);
                    TID[st_int.top()].put_assign();
                    gl();
                }
                else
                    throw curr_lex;
            }
            while (c_type == LEX_COMMA) {
                gl();
                if (c_type != LEX_ID)
                    throw curr_lex;
                else {
                    st_int.push(c_val);
                    gl();
                    if (c_type == LEX_ASSIGN) {
                        gl();
                        if (c_type == LEX_STRC) {
                            TID[st_int.top()].put_value(c_val);
                            TID[st_int.top()].put_assign();
                            gl();
                        }
                        else
                            throw curr_lex;
                    }
                }
            }
            if (c_type == LEX_SEMICOLON) {
                dec(LEX_STRING);
                gl();
                D();
            }
            else
                throw curr_lex;
        }
    }
    else if (c_type == LEX_BOOL) {
        gl();
        if (c_type != LEX_ID)
            throw curr_lex;
        else {
            st_int.push(c_val);
            gl();
            if (c_type == LEX_ASSIGN) {
                gl();
                if (c_type == LEX_FALSE || c_type == LEX_TRUE) {
                    TID[st_int.top()].put_value(c_val);
                    TID[st_int.top()].put_assign();
                    gl();
                }
                else
                    throw curr_lex;
            }
            while (c_type == LEX_COMMA) {
                gl();
                if (c_type != LEX_ID)
                    throw curr_lex;
                else {
                    st_int.push(c_val);
                    gl();
                    if (c_type == LEX_ASSIGN) {
                        gl();
                        if (c_type == LEX_FALSE || c_type == LEX_TRUE) {
                            TID[st_int.top()].put_value(c_val);
                            TID[st_int.top()].put_assign();
                            gl();
                        }
                        else
                            throw curr_lex;
                    }
                }
            }
            if (c_type == LEX_SEMICOLON) {
                dec(LEX_BOOL);
                gl();
                D();
            }
            else
                throw curr_lex;
        }
    }
    else if (c_type != LEX_IF && c_type != LEX_DO && c_type != LEX_WHILE && c_type != LEX_READ &&
            c_type != LEX_WRITE && c_type != LEX_END && c_type != LEX_BEGIN && 
            c_type != LEX_ID && c_type != LEX_PLUS && c_type != LEX_MINUS &&
            c_type != LEX_NUM && c_type != LEX_LPAREN)
        throw curr_lex;
}

void Parser::B() {
    while (c_type != LEX_END)
        S();
}

int pl = -1, c1 = 0, c2 = 0, i1 = 0, i2 = 0, f = 0;

void Parser::S() {
    int pl0, pl1, pl2, pl3, pl4, pl5;
    if (c_type == LEX_IF) {
        gl();
        E0();
        eq_bool();
        pl2 = poliz.size();
        poliz.push_back(Lex());
        poliz.push_back(Lex(POLIZ_FGO));
        S();
        pl3 = poliz.size();
        poliz.push_back(Lex());
        poliz.push_back(Lex(POLIZ_GO));
        poliz[pl2] = Lex(POLIZ_LABEL, poliz.size());
        S1();
        poliz[pl3] = Lex(POLIZ_LABEL, poliz.size());
    }
    else if (c_type == LEX_WHILE) {
        c1 = 1;
        pl0 = poliz.size();
        gl();
        E0();
        eq_bool();
        pl1 = poliz.size(); 
        poliz.push_back(Lex());
        poliz.push_back(Lex(POLIZ_FGO));
        S();
        poliz.push_back(Lex());
        poliz[poliz.size() - 1] = Lex(POLIZ_LABEL, pl0);
        poliz.push_back(Lex(POLIZ_GO));
        poliz[pl1] = Lex(POLIZ_LABEL, poliz.size());
        if (pl != -1 && !i1) {
            poliz[pl] = Lex(POLIZ_LABEL, poliz.size());
            pl = -1;
            f = 0;
            i2 = 0;
        }
        c1 = 0;
    }
    else if (c_type == LEX_DO) {
        c2 = 1;
        pl4 = poliz.size();
        gl();
        S();
        if (c_type == LEX_WHILE) {
            gl();
            E0();
            eq_bool();
            pl5 = poliz.size();
            poliz.push_back(Lex());
            poliz.push_back(Lex(POLIZ_FGO));
            poliz.push_back(Lex());
            poliz[poliz.size() - 1] = Lex(POLIZ_LABEL, pl4);
            poliz.push_back(Lex(POLIZ_GO));
            poliz[pl5] = Lex(POLIZ_LABEL, poliz.size());
            if (pl != -1 && !i2) {
                poliz[pl] = Lex(POLIZ_LABEL, poliz.size());
                pl = -1;
                f = 0;
                i1 = 0;
            }
            if (c_type == LEX_SEMICOLON)
                gl();
            else
                throw curr_lex;
        }
        else
            throw curr_lex;
        c2 = 0;
    }
    else if (c_type == LEX_BREAK) {
        if (c1 && !c2) 
            i2 = 1;
        else if (!c1 && c2)
            i1 = 1;
        else if (!c1 && !c2)
            throw curr_lex;
        gl();
        if (c_type == LEX_SEMICOLON)
            gl();
        else
            throw curr_lex;
        if (!f) {
            pl = poliz.size();
            poliz.push_back(Lex());
            poliz.push_back(Lex(POLIZ_GO));
            f = 1;
        }
    }
    else if (c_type == LEX_READ) {
        gl();
        if (c_type == LEX_LPAREN) {
            gl();
            if (c_type == LEX_ID) {
                check_id_in_read();
                poliz.push_back(Lex(POLIZ_ADDRESS, c_val));
                gl();
            }
            else
                throw curr_lex;
            if (c_type == LEX_RPAREN) {
                gl();
                if (c_type == LEX_SEMICOLON) {
                    gl();
                    poliz.push_back(Lex(LEX_READ));
                }
                else
                    throw curr_lex;
            }
            else
                throw curr_lex;
        }
        else
            throw curr_lex;
    }
    else if (c_type == LEX_WRITE) {
        gl();
        if (c_type == LEX_LPAREN) {
            gl();
            E0();
            while (c_type == LEX_COMMA) {
                gl();
                E0();
            }
            if (c_type == LEX_RPAREN) {
                gl();
                if (c_type == LEX_SEMICOLON) {
                    gl();
                    poliz.push_back(Lex(LEX_WRITE));
                }
                else
                    throw curr_lex;
            }
            else
                throw curr_lex;
        }
        else
            throw curr_lex;
    }
    else if (c_type == LEX_BEGIN) {
        gl();
        B();
        gl();
    }
    else if (c_type == LEX_MINUS || c_type == LEX_PLUS) {
        gl();
        if (c_type == LEX_ID) {
            check_id();
            poliz.push_back(Lex(POLIZ_ADDRESS, c_val));
            gl();
        }
        else
            throw curr_lex;
    }
    else {
        E0();
        if (c_type == LEX_SEMICOLON)
            gl();
        else
            throw curr_lex;
    }
}

void Parser::S1() {
    if (c_type == LEX_ELSE) {
        gl();
        S();
    }
}

void Parser::E0() {
    E1();
    int cnt = 0;
    while (c_type == LEX_ASSIGN) {
        ++cnt;
        if (poliz[poliz.size()-1].get_type() == LEX_ID) {
            c_val = poliz[poliz.size()-1].get_value();
            poliz.pop_back();
            poliz.push_back(Lex(POLIZ_ADDRESS, c_val));
            gl();
            E1();
        }
        else {
            std::cout << poliz[poliz.size()-1] << std::endl;
            throw "before assignment must be identifier!";}
    }
    while (cnt--) {
        eq_type();
        poliz.push_back(Lex(LEX_ASSIGN));
    }
}

void Parser::E1() {
    E2();
    while (c_type == LEX_OR) {
        st_lex.push(c_type);
        gl(); 
        E2();
        check_op();
    }
}
 
void Parser::E2() {
    E3();
    while (c_type == LEX_AND) {
        st_lex.push(c_type);
        gl();
        E3();
        check_op();
    }
}

void Parser::E3() {
    E4();
    if (c_type == LEX_EQ || c_type == LEX_LSS || c_type == LEX_GTR || 
            c_type == LEX_LEQ || c_type == LEX_GEQ || c_type == LEX_NEQ) {
        st_lex.push(c_type);
        gl(); 
        E4();
        check_op();
    }
}

void Parser::E4() {
    T();
    while (c_type == LEX_PLUS || c_type == LEX_MINUS) {
        st_lex.push(c_type);
        gl();
        T();
        check_op();
    }
}

void Parser::T() {
    F();
    while (c_type == LEX_TIMES || c_type == LEX_SLASH || c_type == LEX_MOD) {
        st_lex.push(c_type);
        gl();
        F();
        check_op();
    }
}
 
void Parser::F() {
    if (c_type == LEX_ID) {
        check_id();
        poliz.push_back(Lex(LEX_ID, c_val));
        gl();
    }
    else if (c_type == LEX_NUM) {
        st_lex.push(LEX_INT);
        poliz.push_back(curr_lex);
        gl();
    }
    else if (c_type == LEX_TRUE) {
        st_lex.push(LEX_BOOL);
        poliz.push_back(Lex(LEX_TRUE, 1));
        gl();
    }
    else if (c_type == LEX_FALSE) {
        st_lex.push(LEX_BOOL);
        poliz.push_back(Lex(LEX_FALSE, 0));
        gl();
    }
    else if (c_type == LEX_STRC) {
        st_lex.push(LEX_STRING);
        poliz.push_back(curr_lex);
        gl();
    }
    else if (c_type == LEX_NOT) {
        gl(); 
        F();
        check_not();
    }
    else if (c_type == LEX_MINUS) {
        gl();
        F();
        check_uminus();
    }
    else if (c_type == LEX_PLUS) {
        gl();
        F();
        check_uplus();
    }
    else if (c_type == LEX_LPAREN) {
        gl(); 
        E0();
        if (c_type == LEX_RPAREN)
            gl();
        else
            throw curr_lex;
    }
    else 
        throw curr_lex;
}

void Parser::dec(type_of_lex type) {
    int i;
    while (!st_int.empty()) {
        i = st_int.top();
        st_int.pop();
        if (TID[i].get_declare()) 
            throw "twice";
        else {
            TID[i].put_declare();
            TID[i].put_type(type);
        }
    }
}
 
void Parser::check_id() {
    if (TID[c_val].get_declare())
        st_lex.push(TID[c_val].get_type());
    else 
        throw "not declared";
}
 
void Parser::check_op() {
    type_of_lex t1, t2, op, t = LEX_INT, r = LEX_BOOL;
    t2 = st_lex.top();
    st_lex.pop();
    op = st_lex.top();
    st_lex.pop();
    t1 = st_lex.top();
    st_lex.pop();
    if (op == LEX_PLUS || op == LEX_MINUS || op == LEX_TIMES || op == LEX_SLASH || 
        op == LEX_MOD || op == LEX_ASSIGN)
        r = LEX_INT;
    if (op == LEX_OR || op == LEX_AND)
        t = LEX_BOOL;
    if (t1 == t2 && t1 == LEX_STRING && (op == LEX_PLUS || op == LEX_ASSIGN))
        st_lex.push(LEX_STRING);
    else if (t1 == t2 && t1 == LEX_STRING && (op == LEX_EQ || 
        op == LEX_NEQ || op == LEX_LSS || op == LEX_GTR))
        st_lex.push(LEX_BOOL);
    else if (t1 == t2 && t1 == t) 
        st_lex.push(r);
    else {
        std::cout << Lex(t) << Lex(t1) << Lex(t2) << Lex(op) << Lex(r) << std::endl;
        throw "wrong types are in operation";
    }
    poliz.push_back(Lex(op));
}

void Parser::check_not() {
    if (st_lex.top() != LEX_BOOL)
        throw "wrong type is in not";
    else  
        poliz.push_back(Lex(LEX_NOT));
}

void Parser::check_uminus() {
    if (st_lex.top() != LEX_INT)
        throw "wrong type is in unary minus";
    else  
        poliz.push_back(Lex(LEX_UMINUS));
}

void Parser::check_uplus() {
    if (st_lex.top() != LEX_INT)
        throw "wrong type is in unary plus";
    else  
        poliz.push_back(Lex(LEX_UPLUS));
}

void Parser::eq_type() {
    type_of_lex t = st_lex.top();
    st_lex.pop();
    if (t != st_lex.top()) {
        std::cout << Lex(t) << Lex(st_lex.top()) << std::endl;
        throw "wrong types are in =";
    }
    st_lex.pop();
    st_lex.push(t);
}
 
void Parser::eq_bool() {
    if (st_lex.top() != LEX_BOOL)
        throw "expression is not boolean";
    st_lex.pop();
}
 
void Parser::check_id_in_read() {
    if (!TID[c_val].get_declare())
        throw "not declared";
}

class Executer {
    Lex pc_el;
public:
    void execute(std::vector<Lex> &poliz);
};

void print_stack(std::stack<Ident> &st) {
    if (!st.empty()) {
        Ident buf = st.top();
        st.pop();
        if (st.empty()) {
            if (buf.get_type() == LEX_STRING || buf.get_type() == LEX_STRC)
                std::cout << TS[buf.get_value()] << std::endl;
            else
                printf("%d\n", buf.get_value());
        }
        else {
            print_stack(st);
            if (buf.get_type() == LEX_STRING || buf.get_type() == LEX_STRC)
                std::cout << TS[buf.get_value()] << std::endl;
            else
                printf("%d\n", buf.get_value());
        }
    }
}

void Executer::execute(std::vector<Lex> &poliz) {
    std::stack<Ident> args;
    Ident i, j;
    int index = 0, size = poliz.size();
    while (index < size) {
        pc_el = poliz[index];
        switch(pc_el.get_type()) {
            case LEX_TRUE: 
            case LEX_FALSE: 
            case LEX_NUM:
            case LEX_STRC:
            case POLIZ_ADDRESS: 
            case POLIZ_LABEL:
                i.put_value(pc_el.get_value());
                i.put_type(pc_el.get_type());
                args.push(i);
                break;
            case LEX_ID:
                if (TID[pc_el.get_value()].get_assign()) {
                    args.push(TID[pc_el.get_value()]);
                    break;
                }
                else
                    throw "POLIZ: indefinite identifier";
            case LEX_NOT:
                i = args.top();
                args.pop();
                i.put_value(!i.get_value());
                args.push(i);
                break;
            case LEX_UMINUS:
                i = args.top();
                args.pop();
                i.put_value(-i.get_value());
                args.push(i);
                break;
            case LEX_UPLUS:
                i = args.top();
                args.pop();
                i.put_value(+i.get_value());
                args.push(i);
                break;
            case LEX_OR:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                i.put_value(j.get_value() || i.get_value());
                args.push(i);
                break;
            case LEX_AND:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                i.put_value(j.get_value() && i.get_value());
                args.push(i);
                break;
            case POLIZ_GO:
                i = args.top();
                args.pop();
                index = i.get_value() - 1;
                break;
            case POLIZ_FGO:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                if (!j.get_value()) 
                    index = i.get_value() - 1;
                break;
            case LEX_WRITE:
                print_stack(args);
                while (!args.empty())
                    args.pop();
                break;
            case LEX_READ:
                int k;
                i = args.top();
                args.pop();
                if (TID[i.get_value()].get_type() == LEX_INT) {
                    std::cout << "Input int value for " << TID[i.get_value()].get_name() << std::endl;
                    std::cin >> k;
                }
                else if (TID[i.get_value()].get_type() == LEX_STRING) {
                    std::string s;
                    std::cout << "Input string value for " << TID[i.get_value()].get_name() << std::endl;
                    std::getline(std::cin, s);
                    k = put_TS(s);
                }
                else {
                    std::string j;
                    while (1) {
                        std::cout << "Input boolean value (true or false) for " << TID[i.get_value()].get_name() << std::endl;
                        std::cin >> j;
                        if (j != "true" && j != "false"){
                            std::cout << "Error in input:true/false" << std::endl;
                            continue;
                        }
                        k = (j == "true") ? 1 : 0;
                        break;
                    }
                }
                TID[i.get_value()].put_value(k);
                TID[i.get_value()].put_assign();
                break;
            case LEX_PLUS:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                if (i.get_type() == LEX_STRING || i.get_type() == LEX_STRC)
                    i.put_value(put_TS(TS[j.get_value()] + TS[i.get_value()]));
                else
                    i.put_value(j.get_value() + i.get_value());
                args.push(i);
                break;
            case LEX_TIMES:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                i.put_value(j.get_value() * i.get_value());
                args.push(i);
                break;
            case LEX_MINUS:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                i.put_value(j.get_value() - i.get_value());
                args.push(i);
                break;
            case LEX_SLASH:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                if (i.get_value()) {
                    i.put_value(j.get_value() / i.get_value());
                    args.push(i);
                    break;
                }
                else
                    throw "POLIZ:divide by zero";
            case LEX_MOD:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                if (i.get_value()) {
                    i.put_value(j.get_value() % i.get_value());
                    args.push(i);
                    break;
                }
                else
                    throw "POLIZ:divide by zero";
            case LEX_EQ:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                if (i.get_type() == LEX_STRING || i.get_type() == LEX_STRC) {
                    i.put_value(TS[j.get_value()] == TS[i.get_value()]);
                    if (i.get_value())
                        i.put_type(LEX_TRUE);
                    else
                        i.put_type(LEX_FALSE);
                }
                else
                    i.put_value(j.get_value() == i.get_value());
                args.push(i);
                break;
            case LEX_LSS:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                if (i.get_type() == LEX_STRING || i.get_type() == LEX_STRC) {
                    i.put_value(TS[j.get_value()] < TS[i.get_value()]);
                    if (i.get_value())
                        i.put_type(LEX_TRUE);
                    else
                        i.put_type(LEX_FALSE);
                }
                else
                    i.put_value(j.get_value() < i.get_value());
                args.push(i);
                break;
            case LEX_GTR:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                if (i.get_type() == LEX_STRING || i.get_type() == LEX_STRC) {
                    i.put_value(TS[j.get_value()] > TS[i.get_value()]);
                    if (i.get_value())
                        i.put_type(LEX_TRUE);
                    else
                        i.put_type(LEX_FALSE);
                }
                else
                    i.put_value(j.get_value() > i.get_value());
                args.push(i);
                break;
            case LEX_LEQ:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                i.put_value(j.get_value() <= i.get_value());
                args.push(i);
                break;
            case LEX_GEQ:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                i.put_value(j.get_value() >= i.get_value());
                args.push(i);
                break;
            case LEX_NEQ:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                if (i.get_type() == LEX_STRING || i.get_type() == LEX_STRC) {
                    i.put_value(TS[j.get_value()] != TS[i.get_value()]);
                    if (i.get_value())
                        i.put_type(LEX_TRUE);
                    else
                        i.put_type(LEX_FALSE);
                }
                else
                    i.put_value(j.get_value() != i.get_value());
                args.push(i);
                break;
            case LEX_ASSIGN:
                i = args.top();
                args.pop();
                j = args.top();
                args.pop();
                if (!args.empty())
                    args.push(i);
                TID[j.get_value()].put_value(i.get_value());
                TID[j.get_value()].put_assign(); 
                break;
            default:
                throw "POLIZ: unexpected elem";
        }//end of switch
        ++index;
    };//end of while
    std::cout << "Finish of executing!!!" << std::endl;
}

class Interpretator {
    Parser pars;
    Executer E;
public:
    Interpretator (const char *program) : pars(program) {}
    void interpretation();
};

void Interpretator::interpretation() {
    pars.analyze();
    std::cout << "end of analyze()" << std::endl;
    E.execute(pars.poliz);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "wrong args\n");
        return 1;
    }
    try {
        Interpretator I(argv[1]);
        I.interpretation();
        return 0;
    }
    catch(char c) {
        fprintf(stderr, "unexpected symbol %c\n", c);
    }
    catch(Lex l) {
        std::cout << "unexpected lexeme" << l << std::endl;
    }
    catch(const char *s) {
        fprintf(stderr, "%s\n", s);
    }
    catch(...) {
        fprintf(stderr, "Something strange caught\n");
    }
    return 1;
}
