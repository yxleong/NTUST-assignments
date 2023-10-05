# Taxi Loading Order

## Description
A big family plans to go swimming and orders taxis to take them to the local swimming pool.

Each taxi can accommodate up to 200 kg of weight.

The taxis arrive at the family's house parking lot in a specific order, and the family members fill up each taxi starting from the front seat to the back seat.

After all the taxis are loaded, they exit the parking lot in the reverse order in which they entered. The taxis then arrive at the swimming pool in the same order they departed from the parking lot.

The family members exit the taxi at the swimming pool starting from the front seat to the back seat.

Given a list of each family member's weight in the order they enter the taxis, please print out how many taxis are needed and the order in which the family members exit the taxis at the swimming pool.


### Key points
- The family fills up each taxi starting from the front seat to the back seat.
- They also exit the taxi starting from the front seat to the back seat.
- The taxis arrive at the family's house parking lot in a specific order, and the taxi that arrived first will be filled up first.
- The taxis exit the parking lot in the reverse order of their arrival and go directly to the swimming pool.
- The taxis arrive at the swimming pool in the same order they departed from the parking lot.


## Input
A list of positive integers representing the weights of family members in kilograms, in the order they enter the taxis, separated by space. Each weight will not exceed 200 kg.

## Output
- An integer representing the number of taxis needed to transport the family.
- A list of positive integers representing the weights of family members in the order they exit the taxi at the swimming pool.


## Sample Input
```
90 100 120 40 50 45 87 60 100
```

## Sample Output
```
4
60 100 50 45 87 120 40 90 100
```
