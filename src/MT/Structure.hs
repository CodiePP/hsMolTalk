module MT.Structure
        (
          loadPDBFile
        , header
        , getChain
        , Structure
        ) where

import MT.Chain (Chain)

import Foreign.C.Types
import Foreign.C.String
import Foreign.Ptr
import Foreign.ForeignPtr
import Foreign.ForeignPtr.Unsafe
--import Control.Exception (mask)

import qualified MT.Utils as U

data ExtStructure
newtype Structure = Structure (ForeignPtr ExtStructure)
                    deriving (Eq, Ord, Show)

-- binding the external code
foreign import ccall unsafe mtstructure_get_chain :: (Ptr ExtStructure) -> CChar -> IO (Ptr Chain)

foreign import ccall unsafe mtstructure_header :: (Ptr ExtStructure) -> IO (CString)

foreign import ccall unsafe mtstructure_read :: CString -> IO (Ptr ExtStructure)

foreign import ccall
    "&mtstructure_release"
    mtstructure_release :: FunPtr (Ptr ExtStructure -> IO ())

loadPDBFile :: String -> IO Structure
loadPDBFile name = do
    s <- (withCString name $ \cstr -> mtstructure_read cstr) >>=
         newForeignPtr mtstructure_release
    return $ Structure s

header :: Structure -> IO (String)
header (Structure s) = do
    U.onObjectGetString (unsafeForeignPtrToPtr s) mtstructure_header

getChain :: Structure -> Char -> IO (Ptr Chain)
getChain (Structure s) c = do
    ch <- mtstructure_get_chain (unsafeForeignPtrToPtr s) (castCharToCChar c)
    return ch

