package main
import  (
	"fmt"
)

func main() {
	var stockcode=123
	var enddate="2024-03-27"
	var url="Code=%d&endDate=%s"
	var target_url=fmt.Sprintf(url,stockcode,enddate)
	fmt.Println(target_url)
	
	fmt.Println()
	var target_urll=fmt.Sprintf("Code=%d&endDate=%s",124,"89079(&*%&8")
	fmt.Println(target_urll)		// if this line delete, the last line will be error 

	fmt.Println()
	fmt.Println("Code=%d&endDate=%s",5463,"89079(&*%&8")

	fmt.Println()
	var umll=fmt.Sprintf("Code=%d&endDate=%s",246,"89079(&*%&8")
	fmt.Println(umll)
}