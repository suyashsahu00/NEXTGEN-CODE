import { useState } from 'react'

import { Name } from './components/Name'

import { Navbar } from './components/Navbar'
function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      <Navbar />
      <Name />
    </>
  )
}

export default App
