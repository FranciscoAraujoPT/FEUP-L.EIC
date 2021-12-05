package com.aor.numbers;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import java.util.Arrays;
import java.util.List;

public class ListAggregatorTest {

    private List<Integer> list;
    ListAggregator aggregator;

    @BeforeEach
    public void createRandomList() {
        list = Arrays.asList(1,2,4,2,5);
        aggregator = new ListAggregator();
    }

    @Test
    public void max_bug_7263() {
        list = Arrays.asList(-1,-4,-5);
        int max = aggregator.max(list);

        Assertions.assertEquals(-1, max);
    }

    @Test
    public void sum() {
        int sum = aggregator.sum(list);

        Assertions.assertEquals(14, sum);
    }

    @Test
    public void max() {
        int max = aggregator.max(list);

        Assertions.assertEquals(5, max);
    }

    @Test
    public void min() {
        int min = aggregator.min(list);

        Assertions.assertEquals(1, min);
    }

    @Test
    public void distinct_bug_8726() {
        list = Arrays.asList(1,2,4,2);
        GenericListDeduplicator deduplicator = Mockito.mock(GenericListDeduplicator.class);
        Mockito.when(deduplicator.deduplicate(Mockito.anyList(), Mockito.isNull())).thenReturn(Arrays.asList(1, 2, 4));
        int distinct = aggregator.distinct(list, deduplicator, null);

        Assertions.assertEquals(3, distinct);
    }

    @Test
    public void distinct() {
        GenericListDeduplicator deduplicator = Mockito.mock(GenericListDeduplicator.class);
        Mockito.when(deduplicator.deduplicate(Mockito.anyList(), Mockito.isNull())).thenReturn(Arrays.asList(1, 2, 4, 5));
        int distinct = aggregator.distinct(list, deduplicator, null);

        Assertions.assertEquals(4, distinct);
    }
}
