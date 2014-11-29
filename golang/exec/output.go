package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"os/exec"
)

func main() {
	cmd := exec.Command("odpscmd", "-e", `select count(*) from headlines_id_up_d;`)
	//cmd := exec.Command("echo", "-n", `xxx`)
	stdout, err := cmd.StdoutPipe()
	if err != nil {
		log.Fatal(err)
	}
	stderr, err := cmd.StderrPipe()
	if err != nil {
		log.Fatal(err)
	}
	if err := cmd.Start(); err != nil {
		log.Fatal(err)
	}
	errscanner := bufio.NewScanner(stderr)
	for errscanner.Scan() {
		fmt.Println(errscanner.Text()) // Println will add back the final '\n'
	}
	if err := errscanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
	outscanner := bufio.NewScanner(stdout)
	for outscanner.Scan() {
		fmt.Println(outscanner.Text()) // Println will add back the final '\n'
	}
	if err := outscanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
}
