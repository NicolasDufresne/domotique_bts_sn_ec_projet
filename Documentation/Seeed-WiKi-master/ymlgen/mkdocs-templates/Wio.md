---
title: Wio Introduction
nointro:
---

---
The Wio platform was firstly introduced to the world at the end of 2015 when Wio Link was crowd-founding on Kickstarter. As the second product that we launched at Kickstarter, the result of Wio Link was exceeded our expectation a lot. So not long after that, we released the little brother of Wio link----Wio Node. Both has almost the same function but different in size and grove connector quantity, to accommodate to different situations.

The most attractive thing about Wio must be the virtualizing plug-n-play modules to RESTful APIs with mobile Apps, by using which people can really get rid of soldering, jump wires, and knowledges like electronic engineering, micro-controller programming, network programming, IoT protocols handling. I am not saying that those elements are bad, If you are a beginner, these steps and knowledges are essentially to practice, but sometimes we just want fast prototyping and quick response, and that’s what the Wio was born for, simplify all the steps and make prototyping easy, even if you know nothing about electronics, it is not exaggerate that you can also build a simple IoT project in about 5 minutes.

We have arranged many interesting projects tutorial for you to get started, by using Wio, you are able to water your plant remotely or feed your dog when you aren’t home, wanna dig out what other things you can make with Wio? Check out soon the docs of Wio link and Wio node, have fun!


## Product List
---

Here is the list of the Wio Boards you can find in the Seeed WiKi. The list will be constantly updated.

{{ range .Data.Pages.ByTitle }}{{ $cat1 := trim (index (split .Params.category ",") 0) " "}}{{ $cat2 := trim (index (split .Params.category ",") 1) " "}}{{if or (eq $cat1 "Wio") (eq $cat2 "Wio") }}- [{{.Title}}](/{{.File.BaseFileName}}/){{"\n"}}{{ end }}{{ end }}

