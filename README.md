# CompilerConstruction
### Participants 
- Mohammad Hamza
- Osama Maarouf
- Bilal Shafiq
- Ali Hamza
## Language Specifications:
### Lexical Analyzer Implementation using FA:
There are two tpes of states.
##### Final state:
We read a character as lexem and generate a token. Represented by red circles.
##### Retract State:
Reading a character at final state and retract it to initial state. Represented by yellow circles.

<img src="images/project.jpeg" alt="imag" >


#### Explanation:
- States of FA are represented by digits (0-53).
- 0 state is the starting state.
- On Zero state, there are no transitions when whitespaces, newline and tap characters are occure.
- In case of identifier, when special character <b>@</b> read on <b>0 state</b>, it transits to <b>1 state</b> and so on.
- As input is a stream of characters, after reading a token we retract the reading character to initial state.

## Syntax Analyzer:
#### Grammar:
A grammar is a set of rules, describing how tokens can be combined to create valid language constructs. 
##### Example:
Now we see an example of English grammar and validate the sentences written in english language. 

###### Production Rules:
sentence: nounPhrase verbPhrase
nounPhrase: determiner? noun
verbPhrase: verb nounPhrase
noun: 'dog' | ’school' | 'dina' | ’he' | ’she' | 'homework’ | ...
verb: 'went' | 'ate' | ’said' | ...
determiner: 'the' | 'to' | 'my’ | ...

###### Input String:
Dina went to school           <b>valid</b><br>
She said                      <b>valid</b><br>
The dog ate my homework       <b>valid</b><br>

### FOC Grammar (Subset):

statement:===> agerStatement |sinceStatement |thoughStatement|initStatement<br>
statements:===> statement*<br>
agerStatement:===> 'ager' '(' expression ')’ '{' statements '}’<br>
sinceStatement:===> 'since' '(' expression ')’ '{' statements '}’<br>
initStatement:===> '(int|char)' varName '=' expression '~'<br>
expression:===> term (op term)?<br>
term    :===> varName | constant<br>
varName :===> a string not beginning with a special character @ digit|letter and end with @.<br>
constant:===> a decimal number<br>
op      :===> '+' | '-' | '=' | '>' | '<'<br>

##### input Strings:
- int @hamza@ = 100~<br>   <b>valid</b><br>
- char @x@= @y@ + 'a'~<br> <b>valid</b><br>
- since(1) output("True")~  }<br><b>invalid</b><br>

### Parsing:
Determining if a given input conforms to a grammar

#### Parse Tree:
##### Example:
<img src="images/parse.png" alt="images">
