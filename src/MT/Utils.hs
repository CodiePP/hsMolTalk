module MT.Utils
        (
          onObjectGetString
---     , free
        ) where

import Foreign.C.String
--import Foreign.Ptr


-- binding the external code
foreign import ccall unsafe mtutils_free :: CString -> IO ()

free :: CString -> IO ()
free p = do
    mtutils_free p


onObjectGetString o f = do
    s1 <- f o
    s2 <- peekCString s1
    free s1
    return s2

