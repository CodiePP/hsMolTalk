module MT.Chain
        (
          code
        , number
        , fullPDBCode
        , name
        , description
        , source
        , compound
        , eccode
        , Chain
        ) where

--import Foreign.C.Types
import Foreign.C.String
import Foreign.Ptr
--import Control.Exception (mask)

import qualified MT.Utils as U

data Chain

-- binding the external code
foreign import ccall unsafe mtchain_code :: Ptr Chain -> IO (Char)
foreign import ccall unsafe mtchain_number :: Ptr Chain -> IO (Int)
foreign import ccall unsafe mtchain_name :: Ptr Chain -> IO (CString)
foreign import ccall unsafe mtchain_fullPDBCode :: Ptr Chain -> IO (CString)
foreign import ccall unsafe mtchain_description :: Ptr Chain -> IO (CString)
foreign import ccall unsafe mtchain_source :: Ptr Chain -> IO (CString)
foreign import ccall unsafe mtchain_compound :: Ptr Chain -> IO (CString)
foreign import ccall unsafe mtchain_eccode :: Ptr Chain -> IO (CString)

code :: Ptr Chain -> IO Char
code c = do
    ch <- mtchain_code c
    return ch

number :: Ptr Chain -> IO Int
number c = do
    n <- mtchain_number c
    return n

name :: Ptr Chain -> IO String
name c = do
    U.onObjectGetString c mtchain_name

source :: Ptr Chain -> IO String
source c = do
    U.onObjectGetString c mtchain_source

eccode :: Ptr Chain -> IO String
eccode c = do
    U.onObjectGetString c mtchain_eccode

description :: Ptr Chain -> IO String
description c = do
    U.onObjectGetString c mtchain_description

compound :: (Ptr Chain) -> (IO String)
compound c = do
    U.onObjectGetString c mtchain_compound

fullPDBCode :: Ptr Chain -> IO String
fullPDBCode c = do
    U.onObjectGetString c mtchain_fullPDBCode

