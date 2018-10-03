10 PRINT:PRINT TAB(30): PRINT "CALCUL DE L'IMC"
20 PRINT TAB(29): PRINT"-----------------":PRINT
30 PRINT "Bienvenue dans ce programme de calcul de votre IMC !"
35 PRINT "Attention : Cette formule n'est valable que si vous avez entre 18 et 65 ans !":PRINT
40 INPUT "Quelle est votre taille en m ? ", T
50 INPUT "Ok, et quel est votre poids en kg ? ", P
60 IMC = P / (T * T)
70 PRINT " ": PRINT "Votre IMC est de";IMC;"."
100 IF IMC < 18.5 THEN PRINT "Attention, vous etes maigre."
110 IF IMC >= 18.5 AND IMC < 25 THEN PRINT "Bravo, votre poids est normal !"
120 IF IMC >= 25 AND IMC < 30 THEN PRINT "Attention, vous etes en surpoids."
130 IF IMC >= 30 AND IMC < 40 THEN PRINT "Attention, vous etes obese !"
140 IF IMC >= 40 THEN PRINT "Attention, vous etes en obesite massive !"
150 PRINT
