--{-# LANGUAGE OverloadedStrings #-}

module Main where

import System.Environment

import MT.Structure
import MT.Chain


main :: IO ()
main = do
        putStrLn "hsMolTalk v 2.0"
        args <- getArgs
        case args of
            (fname:chain:[]) -> do
                  let chcode = head chain
                  s <- MT.Structure.loadPDBFile fname
                  putStrLn $ show s
                  h <- MT.Structure.header s
                  putStrLn h
                  c <- MT.Structure.getChain s chcode
                  putStrLn $ show c
                  ci <- MT.Chain.number c
                  ck <- MT.Chain.code c
                  cn <- MT.Chain.name c
                  cs <- MT.Chain.source c
                  ce <- MT.Chain.eccode c
                  cc <- MT.Chain.compound c
                  putStrLn $ "compound: " ++ cc
                  cd <- MT.Chain.description c
                  putStrLn $ "description: " ++ cd
                  putStrLn $ "number: " ++ show ci
                  putStrLn $ "code: " ++ show ck
                  putStrLn $ "name: " ++ cn
                  putStrLn $ "source: " ++ cs
                  putStrLn $ "eccode: " ++ ce

            _ -> do
                  putStrLn "no filename given."

        return ()
