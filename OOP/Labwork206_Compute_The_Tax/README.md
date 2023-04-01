# Compute The Tax

## Problem Statement

This is the tax payment rules for a country. Different income ranges correspond to different tax rates. Please calculate the tax payable of citizens based on this table:

| Income          | Rate              |
|----------------|-------------------|
| Not over $750   | 1% of income      |
| $750—$2,250     | $7.50 plus 2% of amount over $750 |
| $2,250—$3,750   | $37.50 plus 3% of amount over $2,250 |
| $3,750—$5,250   | $82.50 plus 4% of amount over $3,750 |
| $5,250—$7,000   | $142.50 plus 5% of amount over $5,250 |
| Over $7,000     | $230.00 plus 6% of amount over $7,000 |

### Input
Each line represents the income of one citizen, and the income is a float-type number greater than 0.
```
750
2250
4000
```

### Output
Calculate taxes payable for each citizen and print them in order.
```
7.50
37.50
92.50
```

## Additional Information
* Easy, only basic programming syntax and structure are required.
* Solving time: 10 minutes
* Contributors: 張子樂, 鄭鈺哲, 林岳儒
