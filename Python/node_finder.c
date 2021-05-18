// File automatically generated by Parser/asdl_c.py.

#define TRAVERSE(TYPE, NODE) { \
    if ((NODE)) { \
        result = traverse ## TYPE((NODE), tag, flag); \
        if (*flag) { \
            return NULL; \
        } else if (result) { \
            return result; \
        } \
    } \
}

#define TRAVERSE_SEQ(TYPE, SEQ) { \
    for (_i = 0; _i < asdl_seq_LEN((SEQ)); _i++) { \
        TYPE ## _ty elt = (TYPE ## _ty)asdl_seq_GET((SEQ), _i); \
        TRAVERSE((TYPE), elt); \
    } \
}
void *
find_mod(mod_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    switch (node->kind) {
        case Module_kind:
            TRAVERSE_SEQ(stmt, node->body);
            TRAVERSE_SEQ(type_ignore, node->type_ignores);
        case Interactive_kind:
            TRAVERSE_SEQ(stmt, node->body);
        case Expression_kind:
            TRAVERSE(expr, node->body);
        case FunctionType_kind:
            TRAVERSE_SEQ(expr, node->argtypes);
            TRAVERSE(expr, node->returns);
    }
    return result;
}
void *
find_stmt(stmt_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    if (node->node_id == tag) {
        return node;
    }
    switch (node->kind) {
        case FunctionDef_kind:
            TRAVERSE(arguments, node->args);
            TRAVERSE_SEQ(stmt, node->body);
            TRAVERSE_SEQ(expr, node->decorator_list);
            TRAVERSE(expr, node->returns);
        case AsyncFunctionDef_kind:
            TRAVERSE(arguments, node->args);
            TRAVERSE_SEQ(stmt, node->body);
            TRAVERSE_SEQ(expr, node->decorator_list);
            TRAVERSE(expr, node->returns);
        case ClassDef_kind:
            TRAVERSE_SEQ(expr, node->bases);
            TRAVERSE_SEQ(keyword, node->keywords);
            TRAVERSE_SEQ(stmt, node->body);
            TRAVERSE_SEQ(expr, node->decorator_list);
        case Return_kind:
            TRAVERSE(expr, node->value);
        case Delete_kind:
            TRAVERSE_SEQ(expr, node->targets);
        case Assign_kind:
            TRAVERSE_SEQ(expr, node->targets);
            TRAVERSE(expr, node->value);
        case AugAssign_kind:
            TRAVERSE(expr, node->target);
            TRAVERSE(operator, node->op);
            TRAVERSE(expr, node->value);
        case AnnAssign_kind:
            TRAVERSE(expr, node->target);
            TRAVERSE(expr, node->annotation);
            TRAVERSE(expr, node->value);
        case For_kind:
            TRAVERSE(expr, node->target);
            TRAVERSE(expr, node->iter);
            TRAVERSE_SEQ(stmt, node->body);
            TRAVERSE_SEQ(stmt, node->orelse);
        case AsyncFor_kind:
            TRAVERSE(expr, node->target);
            TRAVERSE(expr, node->iter);
            TRAVERSE_SEQ(stmt, node->body);
            TRAVERSE_SEQ(stmt, node->orelse);
        case While_kind:
            TRAVERSE(expr, node->test);
            TRAVERSE_SEQ(stmt, node->body);
            TRAVERSE_SEQ(stmt, node->orelse);
        case If_kind:
            TRAVERSE(expr, node->test);
            TRAVERSE_SEQ(stmt, node->body);
            TRAVERSE_SEQ(stmt, node->orelse);
        case With_kind:
            TRAVERSE_SEQ(withitem, node->items);
            TRAVERSE_SEQ(stmt, node->body);
        case AsyncWith_kind:
            TRAVERSE_SEQ(withitem, node->items);
            TRAVERSE_SEQ(stmt, node->body);
        case Match_kind:
            TRAVERSE(expr, node->subject);
            TRAVERSE_SEQ(match_case, node->cases);
        case Raise_kind:
            TRAVERSE(expr, node->exc);
            TRAVERSE(expr, node->cause);
        case Try_kind:
            TRAVERSE_SEQ(stmt, node->body);
            TRAVERSE_SEQ(excepthandler, node->handlers);
            TRAVERSE_SEQ(stmt, node->orelse);
            TRAVERSE_SEQ(stmt, node->finalbody);
        case Assert_kind:
            TRAVERSE(expr, node->test);
            TRAVERSE(expr, node->msg);
        case Import_kind:
            TRAVERSE_SEQ(alias, node->names);
        case ImportFrom_kind:
            TRAVERSE_SEQ(alias, node->names);
        case Global_kind:
        case Nonlocal_kind:
        case Expr_kind:
            TRAVERSE(expr, node->value);
        case Pass_kind:
        case Break_kind:
        case Continue_kind:
    }
    return result;
}
void *
find_expr(expr_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    if (node->node_id == tag) {
        return node;
    }
    switch (node->kind) {
        case BoolOp_kind:
            TRAVERSE(boolop, node->op);
            TRAVERSE_SEQ(expr, node->values);
        case NamedExpr_kind:
            TRAVERSE(expr, node->target);
            TRAVERSE(expr, node->value);
        case BinOp_kind:
            TRAVERSE(expr, node->left);
            TRAVERSE(operator, node->op);
            TRAVERSE(expr, node->right);
        case UnaryOp_kind:
            TRAVERSE(unaryop, node->op);
            TRAVERSE(expr, node->operand);
        case Lambda_kind:
            TRAVERSE(arguments, node->args);
            TRAVERSE(expr, node->body);
        case IfExp_kind:
            TRAVERSE(expr, node->test);
            TRAVERSE(expr, node->body);
            TRAVERSE(expr, node->orelse);
        case Dict_kind:
            TRAVERSE_SEQ(expr, node->keys);
            TRAVERSE_SEQ(expr, node->values);
        case Set_kind:
            TRAVERSE_SEQ(expr, node->elts);
        case ListComp_kind:
            TRAVERSE(expr, node->elt);
            TRAVERSE_SEQ(comprehension, node->generators);
        case SetComp_kind:
            TRAVERSE(expr, node->elt);
            TRAVERSE_SEQ(comprehension, node->generators);
        case DictComp_kind:
            TRAVERSE(expr, node->key);
            TRAVERSE(expr, node->value);
            TRAVERSE_SEQ(comprehension, node->generators);
        case GeneratorExp_kind:
            TRAVERSE(expr, node->elt);
            TRAVERSE_SEQ(comprehension, node->generators);
        case Await_kind:
            TRAVERSE(expr, node->value);
        case Yield_kind:
            TRAVERSE(expr, node->value);
        case YieldFrom_kind:
            TRAVERSE(expr, node->value);
        case Compare_kind:
            TRAVERSE(expr, node->left);
            TRAVERSE_SEQ(cmpop, node->ops);
            TRAVERSE_SEQ(expr, node->comparators);
        case Call_kind:
            TRAVERSE(expr, node->func);
            TRAVERSE_SEQ(expr, node->args);
            TRAVERSE_SEQ(keyword, node->keywords);
        case FormattedValue_kind:
            TRAVERSE(expr, node->value);
            TRAVERSE(expr, node->format_spec);
        case JoinedStr_kind:
            TRAVERSE_SEQ(expr, node->values);
        case Constant_kind:
        case Attribute_kind:
            TRAVERSE(expr, node->value);
            TRAVERSE(expr_context, node->ctx);
        case Subscript_kind:
            TRAVERSE(expr, node->value);
            TRAVERSE(expr, node->slice);
            TRAVERSE(expr_context, node->ctx);
        case Starred_kind:
            TRAVERSE(expr, node->value);
            TRAVERSE(expr_context, node->ctx);
        case Name_kind:
            TRAVERSE(expr_context, node->ctx);
        case List_kind:
            TRAVERSE_SEQ(expr, node->elts);
            TRAVERSE(expr_context, node->ctx);
        case Tuple_kind:
            TRAVERSE_SEQ(expr, node->elts);
            TRAVERSE(expr_context, node->ctx);
        case Slice_kind:
            TRAVERSE(expr, node->lower);
            TRAVERSE(expr, node->upper);
            TRAVERSE(expr, node->step);
    }
    return result;
}
void *
find_comprehension(comprehension_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    TRAVERSE(expr, node->target);
    TRAVERSE(expr, node->iter);
    TRAVERSE_SEQ(expr, node->ifs);
    return result;
}
void *
find_excepthandler(excepthandler_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    if (node->node_id == tag) {
        return node;
    }
    switch (node->kind) {
        case ExceptHandler_kind:
            TRAVERSE(expr, node->type);
            TRAVERSE_SEQ(stmt, node->body);
    }
    return result;
}
void *
find_arguments(arguments_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    TRAVERSE_SEQ(arg, node->posonlyargs);
    TRAVERSE_SEQ(arg, node->args);
    TRAVERSE(arg, node->vararg);
    TRAVERSE_SEQ(arg, node->kwonlyargs);
    TRAVERSE_SEQ(expr, node->kw_defaults);
    TRAVERSE(arg, node->kwarg);
    TRAVERSE_SEQ(expr, node->defaults);
    return result;
}
void *
find_arg(arg_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    if (node->node_id == tag) {
        return node;
    }
    TRAVERSE(expr, node->annotation);
    return result;
}
void *
find_keyword(keyword_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    if (node->node_id == tag) {
        return node;
    }
    TRAVERSE(expr, node->value);
    return result;
}
void *
find_alias(alias_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    if (node->node_id == tag) {
        return node;
    }
    return result;
}
void *
find_withitem(withitem_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    TRAVERSE(expr, node->context_expr);
    TRAVERSE(expr, node->optional_vars);
    return result;
}
void *
find_match_case(match_case_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    TRAVERSE(pattern, node->pattern);
    TRAVERSE(expr, node->guard);
    TRAVERSE_SEQ(stmt, node->body);
    return result;
}
void *
find_pattern(pattern_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    if (node->node_id == tag) {
        return node;
    }
    switch (node->kind) {
        case MatchValue_kind:
            TRAVERSE(expr, node->value);
        case MatchSingleton_kind:
        case MatchSequence_kind:
            TRAVERSE_SEQ(pattern, node->patterns);
        case MatchMapping_kind:
            TRAVERSE_SEQ(expr, node->keys);
            TRAVERSE_SEQ(pattern, node->patterns);
        case MatchClass_kind:
            TRAVERSE(expr, node->cls);
            TRAVERSE_SEQ(pattern, node->patterns);
            TRAVERSE_SEQ(pattern, node->kwd_patterns);
        case MatchStar_kind:
        case MatchAs_kind:
            TRAVERSE(pattern, node->pattern);
        case MatchOr_kind:
            TRAVERSE_SEQ(pattern, node->patterns);
    }
    return result;
}
void *
find_type_ignore(type_ignore_ty node, int tag, int *flag)
{
    int _i = 0;
    void *result = NULL;
    switch (node->kind) {
        case TypeIgnore_kind:
    }
    return result;
}
void *
find_node(mod_ty tree, int tag)
{
    int error_flag = 0;
    void *result = find_mod(tree, tag, *error_flag);
    assert(result == NULL || !error_flag);
    return result;
}
