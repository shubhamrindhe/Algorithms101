typedef enum { AND = '&', OR = '|',  NOT = '!' } OPS;

/*
bool _and_(int *a, char *b);
bool _or_(int *a, char *b);
bool _not_(int *a, char *b);

bool _or_(int* idx, char* expression) {
    char _ = '\0';
    bool flag = false;
    while ((_ = expression[(*idx)++]) && _ != ')') {
        switch (_) {
            case AND:
                if (_and_(idx, expression)) flag = true;
                break;
            case OR:
                if (_or_(idx, expression)) flag = true;
                break;
            case NOT:
                if (_not_(idx, expression)) flag = true;
                break;
            case ',':
                break;
            case 't':
                flag = true;
                break;
        }
    }

    return flag;
}

bool _not_(int* idx, char* expression) {
    char _ = '\0';
    bool flag = false;

    while ((_ = expression[(*idx)++]) && _ != ')') {
        switch (_) {
            case AND:
                flag = !_and_(idx, expression);
                break;
            case OR:
                flag = !_or_(idx, expression);
                break;
            case NOT:
                flag = !_not_(idx, expression);
                break;
            case 't':
                flag = false;
                break;
            case 'f':
                flag = true;
                break;
            default:
                break;
        }
    }

    return flag;
}

bool _and_(int* idx, char* expression) {
    char _ = '\0';
    bool flag = true;

    while ((_ = expression[(*idx)++]) && _ != ')') {
        switch (_) {
            case AND:
                if (!_and_(idx, expression)) flag = false;
                break;
            case OR:
                if (!_or_(idx, expression)) flag = false;
                break;
            case NOT:
                if (!_not_(idx, expression)) flag = false;
                break;
            case ',':
                break;
            case 'f':
                flag = false;
                break;
        }
    }

    return flag;
}
*/

bool eval_bool_expr(int* idx, char* expression, OPS type) {
    char _ = '\0';
    bool flag = type == AND;
    while ((_ = expression[(*idx)++]) && _ != ')') {
        switch (_) {
            case 'f':
                if (type == AND) flag = false;
                if (type == NOT) flag = true;
                break;
            case 't':
                if (type == OR) flag = true;
                if (type == NOT) flag = false;
                break;
            case ',':
                break;
            // SUBEXPRESSION
            // case AND:
            //     subexpr_t = AND;
            //     sub_expr_result = eval_bool_expr(idx, expression, AND);
            //     if (type == AND && !sub_expr_result) flag = false;
            //     if (type == OR && sub_expr_result) flag = true;
            //     if (type == NOT) flag = !sub_expr_result;
            //     break;
            // case OR:
            //     subexpr_t = OR;
            //     sub_expr_result = eval_bool_expr(idx, expression, OR);
            //     if (type == AND && !sub_expr_result) flag = false;
            //     if (type == OR && sub_expr_result) flag = true;
            //     if (type == NOT) flag = !sub_expr_result;
            //     break;
            // case NOT:
            //     subexpr_t = NOT;
            //     sub_expr_result = eval_bool_expr(idx, expression, NOT);
            //     if (type == AND && !sub_expr_result) flag = false;
            //     if (type == OR && sub_expr_result) flag = true;
            //     if (type == NOT) flag = !sub_expr_result;
            //     break;
            case AND:
            case OR:
            case NOT: {
                OPS subexpr_t = (_ == AND) ? AND : (_ == OR) ? OR : NOT;
                bool sub_expr_result = eval_bool_expr(idx, expression, subexpr_t);
                if (type == AND) {
                    flag &= sub_expr_result;
                } else if (type == OR) {
                    flag |= sub_expr_result;
                } else if (type == NOT) {
                    flag = !sub_expr_result;
                }
                break;
            }
        }
    }

    return flag;
}

bool parseBoolExpr(char* expression) {
    int idx = 0b0;
    // switch (expression[idx++]) {
    //     case NOT:
    //         return _not_(&idx, expression);
    //     case AND:
    //         return _and_(&idx, expression);
    //     case OR:
    //         return _or_(&idx, expression);
    // }

    // exit(0);
    // return false;

    char _ = expression[idx++];
    OPS expr_t = (_ == AND) ? AND : (_ == OR) ? OR : NOT;
    return eval_bool_expr(&idx, expression, expr_t);
}
