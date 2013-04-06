#include <iostream>
#include <vector>
#include <math.h>



class NVarDeclaration;
class NExpression;
class NStatement
class NElseifStatement;

typedef std::vector<NVarDeclaration*> VariableList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NStatement*> StatementList;
typedef std::vector<NElseifStatement*> ElseifList;


class Node {
public:
	virtual ~Node() {}
};


class NStatement : public Node {

};


class NFunction : public NStatement {
public:
	const NIdentifier& type;
	const NIdentifier& id;
	VariableList args;
	NInstructions& instructions;
	NFunction(const NIdentifier& type, const NIdentifier& id,
			  const VariableList& args, NInstructions instructions) :
		type(type), id(id), args(args), instructions(instructions) {}

};


class NVarDeclaration : public NStatement {
public:
	const NIdentifier& type;
	NIdentifier& id; // const ??
	NExpression *expr;
	NVarDeclaration(const NIdentifier& type, NIdentifier& id) :
		type(type), id(id) {}

	NVarDeclaration(const NIdentifier& type, NIdentifier& id, NExpression *expr) :
		type(type), id(id), expr(expr) {}
};


class NExpressionStatement : public NStatement {
public:
	NExpression& expr;
	NExpressionStatement(NExpressionStatement& expr) : expr(expr) {}
};


/*TODO : A partir de ce point, verifier pour les const !*/
class NIfStatement : public NStatement
{
public:
    NCondition& condition;
    NInstructions& instructions;
    ElseifList elseiflist;
    NElseStatement elseStatement;
    NIfStatement(NCondition& condition, NInstructions& instructions, NElseifStatement& elseiflist, NElseStatement elseStatement) :
        condition(condition), instructions(instructions), elseiflist(elseiflist), elseStatement(elseStatement) {}
    NIfStatement(NCondition& condition, NInstructions& instructions, NElseifStatement& elseiflist):
        condition(condition), instructions(instructions), elseiflist(elseiflist) {}
    NIfStatement(NCondition& condition, NInstructions& instructions) : condition(condition), instructions(instructions) {}
    NIfStatement(NCondition& condition) : condition(condition) {}
};

class NElseifStatement : public NStatement
{
    NCondition& condition;
    NInstructions& instructions;
    NElseifStatement(NCondition& condition, NInstructions& instructions) : condition(condition), instructions(instructions) {}
    NElseifStatement(NCondition& condition) : condition(condition) {}
};

class NElseStatement : public NStatement
{
    NInstructions& instructions;
    NElseStatement(NInstructions& instructions) : instructions(instructions) {}
    NElseStatement() {}
};


class NLoopStatement : public NStatement {
public:
	NCondition& condition;
	NInstructions& instructions;
	NLoopStatement(NCondition& condition, NInstructions& instructions) :
		condition(condition), instructions(instructions) {}
};


class NForStatement : public NStatement {
public:
	NIdentifier& id;
	NLadder& ladder;
	NInstructions& instructions;
	NForStatement(NIdentifier& id, NLadder& ladder, NInstructions& instructions) :
		id(id), ladder(ladder), instructions(instructions) {}
};


class NLadder : public Node { // TODO : Check const (definition + constructeur)
public:
	const NNumb& bLadder; 
	const NNumb& eLadder;
	NNumb& step;
	NLadder(NNumb& bLadder, NNumb& eLadder) :
		bLadder(bLadder), eLadder(eLadder), step(1) {}

	NLadder(NNumb& bLadder, NNumb& eLadder, NNumb& step) :
		bLadder(bLadder), eLadder(eLadder), step(step) {}
};





class NExpression : public Node {};


class NNumb : public NExpression
{
public:
    int valueInt;
    float valueFloat;
    bool intUsed;
    NNumb(int valueInt, bool intUsed) : valueInt(valueInt) intUsed(intUsed) {}
    NNumb(float valueFloat, bool intUsed) : valueFloat(valueFloat) intUsed(intUsed) {}
    NNumb(double value)
    {
        if (fmod(value, 1) == 0)
        {
            this->valueInt = value;
            this->intUsed = true;
        }
        else
        {
            this->valueFloat = value;
            this->intUsed = false;
        }

    }
};

class NIdentifier : public NExpression
{
public:
    std::string name;
    NIdentifier(const std::string& name) : name(name) {}
};

class NBinaryOperator : NExpression
{
public:
    int op; //const?
    NExpression& left;
    NExpression& right;
    NBinaryOperator(NExpression& left, int op, NExpression& right) :
        op(op), left(left), right(right) {}
};

class NAssignment : NExpression
{
public:
    NIdentifier& ident;
    NExpression& expression;
    NAssignment(NIdentifier& ident, NExpression& expression) : ident(ident), expression(expression) {}
};

class NFonctionCall : NExpression
{
public:
    NIdentifier& id;
    ExpressionList args;
    NFonctionCall(const NIdentifier& id, ExpressionList& args) : id(id), args(args) {}
    NFonctionCall(const NIdentifier& id) : id(id) {}
};

class NInstructions : public NExpression
{
public:
    StatementList statements;
    NInstructions() {}
};




/*TODO : A partir de ce point, verifier pour les const !*/
class NCondition : public Node {};

class NConditionConstant : public NExpression
{
public:
    bool value;
    NConditionConst(bool value) : value(value) {}
};

class NCondition : public NCondition
{
public:
    NExpression& leftExp;
    NExpression& rightExp;
    int op;
    NConditionComparator(NExpression& leftExp, int op, NExpression& rightExp) : leftExp(leftExp), op(op), rightExp(rightExp) {}
};



