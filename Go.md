(内容大部分为GPT创作QAQ)

变量定义时
gorm 指定变量数据库对应的名称
json 指定json格式化时对应的名称


# string
+ strings.Replace 方法来替换字符串中的子串。strings.Replace 方法的函数签名
```GO
func Replace(s, old, new string, n int) string
```
    + s：原始字符串。
    + old：要被替换的子串。
    + new：替换后的子串。
    + n：指定替换次数，如果为 -1，则表示替换所有匹配的子串。


+ strings.TrimSpace 是 Go 语言中的一个字符串处理函数，用于去除字符串的首尾空白字符（包括空格、制表符、换行符等

+ json.Unmarshal 是 Go 编程语言中用于将 JSON 数据解析为 Go 对象（结构体、切片、映射等）的函数。它是 Go 标准库中的一个函数，用于处理 JSON 数据的反序列化。

+ strings.HasPrefix 是 Go 语言中的一个函数，用于检查字符串是否以指定的前缀开头

+ strings.TrimSuffix 是 Go 语言中的一个字符串处理函数，用于去除字符串的后缀

### Timer
在Go语言的time包中，AddDate()函数用于将指定的年、月、日数量添加到给定的时间中，并返回一个新的时间。
```GO
func (t Time) AddDate(years int, months int, days int) Time
```

### http
创建一个HTTP请求对象
```GO
func NewRequest(method, url string, body io.Reader) (*http.Request, error)
```
+ method是一个字符串，表示HTTP请求的方法，例如"GET"、"POST"、"PUT"等。
+ url是一个字符串，表示请求的URL。
+ body是一个io.Reader接口类型的参数，用于提供请求的主体内容。可以使用strings.Reader、bytes.Buffer等类型来创建一个io.Reader
返回值：
+ *http.Request是一个表示HTTP请求的结构体，包含了请求的各种属性，例如URL、方法、请求头、请求体等。
+ error表示在创建请求时是否发生了错误，如果没有错误则为nil。

用于发送HTTP请求并返回响应
```GO
func (c *Client) Do(req *Request) (*Response, error)
```
+ req是一个*http.Request类型的参数，表示要发送的HTTP请求。
返回值：

+ *http.Response是一个表示HTTP响应的结构体，包含了响应的各种属性，例如状态码、响应头、响应体等。
+ error表示在发送请求或接收响应时是否发生了错误，如果没有错误则为nil

```GO
type Response struct {
    Status     string // 状态行，例如 "200 OK"
    StatusCode int    // 状态码，例如 200
    Header     Header // 响应头
    Body       io.ReadCloser // 响应体
    // ...
}
```

```GO
type Request struct {
    Method           string
    URL              *url.URL
    Proto            string
    ProtoMajor       int
    ProtoMinor       int
    Header           Header
    Body             io.ReadCloser
    ContentLength    int64
    TransferEncoding []string
    Close            bool
    Host             string
    Form             url.Values
    PostForm         url.Values
    MultipartForm    *multipart.Form
    Trailer          Header
    RemoteAddr       string
    RequestURI       string
    TLS              *tls.ConnectionState
    Cancel           <-chan struct{}
    Response         *Response
    ctx              context.Context
}
```
+ Method：获取或设置HTTP请求的方法，如GET、POST、PUT等。
+ URL：获取或设置HTTP请求的URL。
+ Header：获取或设置HTTP请求的头部信息。
+ Body：获取或设置HTTP请求的主体（请求体）。
+ Form：获取解析后的URL编码表单数据。
+ PostForm：获取解析后的POST表单数据。
+ MultipartForm：获取解析后的多部分表单数据。
+ RemoteAddr：获取客户端的网络地址。
+ TLS：获取TLS连接状态信息（如果使用了TLS）。

用于设置HTTP请求或响应的头部信息中的指定字段的值
```GO
func (h Header) Set(key, value string)
```

### 开源库zap
用与管理日志
```GO
func (log *Logger) Info(msg string, fields ...Field)
```
后面可以通过添加特定的方法 加入属性名+属性获得更多信息

### 开源库gorm
开源 ORM（对象关系映射）库，用于简化数据库操作
[官方文档](https://gorm.io/zh_CN/docs/index.html)

语句中的? 可以是一个占位符，内容由后面的变量补充

gorm.DB 提供了 **Model** 方法用于指定查询的模型。通过 Model 方法，你可以指定要查询的数据库表对应的模型

**Debug**是 gorm.DB 结构体提供的一个方法，用于开启或关闭调试模式
1. 调用 Debug() 方法，将调试模式设置为开启状态
2. 调用 Debug(true) 方法，将调试模式设置为开启状态

**Find** 是 gorm.DB 结构体的一个方法，用于执行查询操作并将查询结果存储到指定的变量中。
Find 方法可以指定任意的数据类型作为目标变量，但需要满足以下要求：
1. 目标变量必须是一个指针类型。这是因为 Find 方法需要将查询结果存储到目标变量中，而只有指针类型才能在函数内部修改变量的值。
2. 目标变量的类型必须与查询结果的数据结构匹配。例如，如果查询结果是一个包含多个字段的结构体，那么目标变量也必须是相同结构体类型的指针。

**ErrorLog** 决定了 GORM 在执行数据库操作时输出的错误日志的内容和位置
