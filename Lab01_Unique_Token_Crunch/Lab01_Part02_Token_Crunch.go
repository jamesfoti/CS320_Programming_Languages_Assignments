/*
Lab 1 (Part 2 - Token Crunch)
James Foti
Red ID: 820124143
CS 320
Professor Healey
6/13/2019
*/

package main

import (
    "bufio"
    "fmt"
    "log"
    "os"
    "math/rand"
    "time"
 )

func main() {
	fmt.Print("Enter file name: ")
	var fileName string
	fmt.Scanln(&fileName) // file name: juliet.out.txt

    file, err := os.Open(fileName)
    if err != nil {
        log.Fatal(err)
    }

	scanner := bufio.NewScanner(file)
	scanner.Split(bufio.ScanLines)
    var listOfTokens []string

    for scanner.Scan() {
    	listOfTokens = append(listOfTokens, scanner.Text())
    }

    file.Close()

	s := rand.NewSource(time.Now().Unix())
	r := rand.New(s) 
	var length = len(listOfTokens)


	var firstRanIndex = r.Intn(length)

	var secondRanIndex = r.Intn(length)
	if (secondRanIndex == firstRanIndex) {
		secondRanIndex = r.Intn(length)
	}

	var thirdRanIndex = r.Intn(length)
	if (thirdRanIndex == firstRanIndex || thirdRanIndex == secondRanIndex) {
		thirdRanIndex = r.Intn(length)
	}
	var fourthRanIndex = r.Intn(length)
	if (fourthRanIndex == firstRanIndex || fourthRanIndex == thirdRanIndex || fourthRanIndex == firstRanIndex) {
		fourthRanIndex = r.Intn(length)
	}

	var firstToken = listOfTokens[firstRanIndex]
	var secondToken = listOfTokens[secondRanIndex]
	var thirdToken = listOfTokens[thirdRanIndex]
	var fourthToken = listOfTokens[fourthRanIndex]

	fmt.Println("1st token:", firstToken)
	fmt.Println("2nd token:", secondToken)
	fmt.Println("3rd token:", thirdToken)
	fmt.Println("4th token:", fourthToken)

	var tokenPassword = firstToken + secondToken + thirdToken + fourthToken
	fmt.Println("Combined token password:", tokenPassword)
}
