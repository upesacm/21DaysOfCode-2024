"use client";
import React from "react";
import {Button, Link, Accordion, AccordionItem} from "@nextui-org/react";
import {AnchorIcon} from "./AnchorIcon";

export default function Home() {
  
    return (
      <div className="center-everything">
    <Accordion>

      <AccordionItem key="1" aria-label="Accordion 1" subtitle={
        <span>  Create Two buttons one with your name and other with your SapID. <span role="img">👇</span>
        </span>
        } title="Task 1" >
      <Button color="default" variant="shadow" style={{ marginRight: '10px' }}>
        Supragya Gandotra
      </Button>   
      <Button color="default" variant="shadow">
        500107073
      </Button> 
      </AccordionItem>

      <AccordionItem
        key="2"
        aria-label="Accordion 2"
        subtitle={
          <span>
            Create a paragraph and write two different sentences  <span role="img">👇</span>
          </span>
        }
        title="Task 2"
      >
        <h1 style={{ color: '#ffc83d' }}>Hello</h1>
        <h6 style={{ color: '#ffc83d' }}>It has been nice knowing ou all.</h6>
      </AccordionItem>

      <AccordionItem key="3" aria-label="Accordion 3" subtitle={
        <span>  Create a link to www.upesacmw.org and open website in a new tab <span role="img">👇</span>
        </span>
       }title="Task 3">
        <Link
      isExternal
      showAnchorIcon
      size ="md"
      href="https://www.upesacmw.org/"
      anchorIcon={<AnchorIcon />}>
      Go to upesacmw
    </Link>
      </AccordionItem>

      <AccordionItem key="4" aria-label="Accordion 4" subtitle={
        <span>  Press to expand <span role="img">👇</span>
        </span>
       }title="Task 4">
        <div>
        <Link
      isExternal
      showAnchorIcon
      size ="sm"
      href="https://www.amazon.in/"
      anchorIcon={<AnchorIcon />}>
      Back To Amazon
    </Link>
    <br></br>
    Nike Black Running Shoes
    <br></br>
    $39 - in stock.
    <br></br>
    Free delivery tomorrow.
    <br></br>
    <Button color="default" variant="shadow" style={{ marginRight: '10px' }}>
        Add to Cart
      </Button>   
      <Button color="default" variant="shadow">
        Buy Now
      </Button> 
      </div>
      </AccordionItem>
    </Accordion>
    </div>
  );
}
