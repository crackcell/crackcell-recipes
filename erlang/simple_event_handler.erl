%%%-*- encoding: utf-8; indent-tabs-mode: nil -*-
%%%-------------------------------------------------------------------
%%% @author Tan Menglong <tanmenglong@gmail.com>
%%% @copyright (c) 2013, Tan Menglong
%%% @doc
%%% file desc
%%% @end
%%% Created : Thu Aug  1 09:47:41 2013
%%%-------------------------------------------------------------------

-module(simple_event_handler).
-author("crackcell").
-export([start/1, event_loop/1]).

%%%===================================================================
%%% API
%%%===================================================================

start(Name) ->
	register(Name, spawn(fun() -> event_loop(fun no_op/1) end)).

event_loop(Fun) ->
	receive
		{add, Func2} ->
			event_loop(Func2);
		{event, Any} ->
			(catch Fun(Any)),
			event_loop(Fun)
	end.

no_op(Any) ->
	io:format("~w~n", Any).

%%%===================================================================
%%% Internal functions
%%%===================================================================


%%%===================================================================
%%% Unit tests
%%%===================================================================
-ifdef(TEST).
-include_lib("eunit/include/eunit.hrl").
-endif.
