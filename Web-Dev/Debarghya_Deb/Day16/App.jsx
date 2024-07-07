import React from 'react'
import GreetUser from './Components/GreetUser'
import NameForm from './Components/NameForm'
import InputLengthChecker from './Components/InputLengthChecker'

function App() {
  return (
    <div>
      <GreetUser username = "Dev!"/>
       <NameForm />
        <InputLengthChecker />
    </div>
  )
}

export default App